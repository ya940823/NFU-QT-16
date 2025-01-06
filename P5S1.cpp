#include "P5S1.hpp"
#include "CircuitComponent.hpp"

P5S1::P5S1(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene(scene), player(new QMediaPlayer(this)),audioOutput(new QAudioOutput(this)),bz(nullptr) {
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 800, 600);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(1); // 設置音量
    QString soundFilePath = QCoreApplication::applicationDirPath() + "/resources/sound.mp3";
    if (!QFile::exists(soundFilePath)) {
        qWarning() << "Sound file not found:" << soundFilePath;
    } else {
        qDebug() << "Sound file loaded:" << soundFilePath;
    }
    player->setSource(QUrl::fromLocalFile(soundFilePath));

    // 確保音效循環播放
    connect(player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            player->play();
        }
    });

    // Initialize components
    nfb = new CircuitComponent("NFB");
    cos1 = new CircuitComponent("COS1");
    pb1 = new CircuitComponent("PB1");
    pb2 = new CircuitComponent("PB2");
    ems = new CircuitComponent("EMS");
    thRy = new CircuitComponent("TH_RY");
    mc1 = new CircuitComponent("MC1");
    mc2 = new CircuitComponent("MC2");
    mc3 = new CircuitComponent("MC3");
    t1 = new CircuitComponent("T1");
    pl1 = new CircuitLamp("PL1");
    pl2 = new CircuitLamp("PL2");
    pl3 = new CircuitLamp("PL3");
    pl4 = new CircuitLamp("PL4");
    bz = new CircuitLamp("BZ");

    // Set positions
    nfb->setPos(50, 50);
    cos1->setPos(100, 50);
    pb1->setPos(150, 50);
    pb2->setPos(200, 50);
    //ems->setPos(250, 50);
    thRy->setPos(250, 50);
    mc1->setPos(100, 150);
    mc2->setPos(200, 150);
    mc3->setPos(300, 150);
    t1->setPos(400, 150);
    pl1->setPos(450, 50);
    pl2->setPos(500, 50);
    pl3->setPos(550, 50);
    pl4->setPos(600, 50);
    bz->setPos(650, 50);

    // Initialize PB1 button
    PB1Button *pb1Button = new PB1Button("PB1");
    pb1Button->setFixedSize(50, 50);

    // Add button to scene using QGraphicsProxyWidget
    QGraphicsProxyWidget *proxy = scene->addWidget(pb1Button);
    proxy->setPos(150, 50);
    // Add to scene
    scene->addItem(nfb);
    scene->addItem(cos1);
    scene->addItem(pb1);
    scene->addItem(pb2);
    //scene->addItem(ems);
    scene->addItem(thRy);
    scene->addItem(mc1);
    scene->addItem(mc2);
    scene->addItem(mc3);
    scene->addItem(t1);
    scene->addItem(pl1);
    scene->addItem(pl2);
    scene->addItem(pl3);
    scene->addItem(pl4);
    scene->addItem(bz);

    // Connect button signals
    connect(pb1Button, &PB1Button::pressed, this, &P5S1::handlePB1Pressed);
    connect(pb1Button, &PB1Button::released, this, &P5S1::handlePB1Released);

    connect(nfb, &CircuitComponent::pressed, this, &P5S1::handlePB1Pressed);

    // Connect PB2 button signal for motor start
    connect(pb2, &CircuitComponent::pressed, this, &P5S1::handlePB2Pressed);
    connect(cos1, &CircuitComponent::pressed, this, &P5S1::handlecos1Pressed);

    // Connect TH_RY abnormal state
    connect(thRy, &CircuitComponent::pressed, this, &P5S1::handleTHRYTriggered);

    resetCircuit(); // Initialize circuit
}

void P5S1::handlecos1Pressed() { //cos1 true:1, cos1 false:2
    if(cos1->isActive())cos1->setActive(false);
    else cos1->setActive(true);
    if(cos1->isActive() && thRy->isActive()){ //cos1 true:1
        //thry up
        resetCircuit();
        bz->setOn(true);
        onBzLightUp();
        pl3->setOn(true);
        pl4->setOn(false);
    }
    else if(!cos1->isActive() && thRy->isActive()){
        //thry up
        resetCircuit();
        bz->setOn(false);
        stopBzSound();
        pl3->setOn(true);
        pl4->setOn(false);
    }
    else if(cos1->isActive() && !thRy->isActive()){ //cos1 true:1
        bz->setOn(false);
        stopBzSound();
        pl3->setOn(false);
        pl4->setOn(true);
    }
    else if(!cos1->isActive() && !thRy->isActive()){
        bz->setOn(false);
        stopBzSound();
        pl3->setOn(false);
        pl4->setOn(true);
    }
}

void P5S1::handlePB1Pressed() {
    qDebug() << "PB1 Pressed: Stopping motor";
    if(!thRy->isActive()) stopMotor();
}

void P5S1::handlePB1Released() {
    qDebug() << "PB1 Released: PL4 On";
    if(!thRy->isActive()) pl4->setOn(true);
}

void P5S1::handlePB2Pressed() {
    qDebug() << "PB2 Pressed: Starting motor in Y configuration";
    if(!thRy->isActive()) {
        mc1->setActive(true);
        mc2->setActive(false);
        mc3->setActive(true);
        pl1->setOn(true);
        pl4->setOn(false);
        t1->setActive(true);

        // Simulate timer behavior for switching to Delta configuration
        QTimer::singleShot(5000, this, [this]() {
            qDebug() << "T1 Timer elapsed: Switching to Delta configuration";
            if(!thRy->isActive()) {
                mc1->setActive(true);
                mc3->setActive(false);
                mc2->setActive(true);
                pl1->setOn(false);
            }
            //pl2->setOn(true);
        });
    }
}

void P5S1::handleTHRYTriggered() {
    qDebug() << "TH_RY Triggered: Stopping motor and handling COS1 behavior";
    stopMotor();

    if (thRy->isActive())thRy->setActive(false); //thry true: up
    else thRy->setActive(true);
    if(cos1->isActive() && thRy->isActive()){ //cos1 true:1, cos1 false:2
        //thry up
        resetCircuit();
        bz->setOn(true);
        onBzLightUp();
        pl3->setOn(false);
        pl4->setOn(false);
    }
    else if(!cos1->isActive() && thRy->isActive()){
        //thry up
        resetCircuit();
        bz->setOn(false);
        stopBzSound();
        pl3->setOn(true);
        pl4->setOn(false);
    }
    else if(cos1->isActive() && !thRy->isActive()){
        bz->setOn(false);
        stopBzSound();
        pl3->setOn(false);
        pl4->setOn(true);
    }
    else if(!cos1->isActive() && !thRy->isActive()){
        bz->setOn(false);
        stopBzSound();
        pl3->setOn(false);
        pl4->setOn(true);
    }
}

void P5S1::stopMotor() {
    mc1->setActive(false);
    mc2->setActive(false);
    mc3->setActive(false);
    t1->setActive(false);
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
    pl4->setOn(false);
    bz->setOn(false);
    stopBzSound();
}

void P5S1::resetCircuit() {
    qDebug() << "Resetting Circuit";
    stopMotor();
    pl4->setOn(true);
    nfb->setActive(true);
}

void P5S1::onBzLightUp() {
    if (player->playbackState() != QMediaPlayer::PlayingState) {
        qDebug() << "BZ is lighting up! Playing sound.";
        player->play();
    } else {
        qDebug() << "BZ is already playing. Skipping play.";
    }
}

void P5S1::stopBzSound() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        qDebug() << "Stopping BZ sound.";
        disconnect(player, &QMediaPlayer::playbackStateChanged, nullptr, nullptr); // 暫時斷開連接
        player->stop();
        connect(player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState state) {
            if (state == QMediaPlayer::StoppedState) {
                player->play();
            }
        });
    } else {
        qDebug() << "BZ sound is not playing. Skipping stop.";
    }
    bz->setOn(false); // 確保燈關閉
}
