#include "P7S5.hpp"
#include "CircuitComponent.hpp"

P7S5::P7S5(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene(scene), frTimer(new QTimer(this)), FRBlinking(false), player(new QMediaPlayer(this)), audioOutput(new QAudioOutput(this)), bz(nullptr) {
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 800, 600);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(1);

    QString soundFilePath = QCoreApplication::applicationDirPath() + "/resources/sound.mp3";
    if (!QFile::exists(soundFilePath)) {
        qWarning() << "Sound file not found:" << soundFilePath;
    } else {
        qDebug() << "Sound file loaded:" << soundFilePath;
    }
    player->setSource(QUrl::fromLocalFile(soundFilePath));

    connect(player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            player->play();
        }
    });


    // Initialize components
    nfb = new CircuitComponent("NFB");
    fr = new CircuitComponent("FR"); //
    pb1 = new CircuitComponent("PB1");

    pb2 = new CircuitComponent("PB2");
    pb3 = new CircuitComponent("PB3");
    pb4 = new CircuitComponent("PB4");
    x1 = new CircuitComponent("X1");
    x2 = new CircuitComponent("X2");
    x3 = new CircuitComponent("X3");
    ls1 = new CircuitComponent("LS1");
    ls2 = new CircuitComponent("LS2");
    mcf = new CircuitComponent("MCF");
    mcr = new CircuitComponent("MCR");
    t1 = new CircuitComponent("T1");
    t2 = new CircuitComponent("T2");
    ol = new CircuitComponent("OL");
    pl1 = new CircuitLamp("PL1");
    pl2 = new CircuitLamp("PL2");
    pl3 = new CircuitLamp("PL3");
    pl4 = new CircuitLamp("PL4");
    bz  = new CircuitLamp("BZ");
    PB4Button *pb4Button = new PB4Button("PB4");
    pb4Button->setFixedSize(50, 50);
    QGraphicsProxyWidget *proxy = scene->addWidget(pb4Button);
    proxy->setPos(300, 50);
    PB4Button *ls1Button = new PB4Button("ls1");
    ls1Button->setFixedSize(50, 50);
    QGraphicsProxyWidget *proxy2 = scene->addWidget(ls1Button);
    proxy2->setPos(500, 50);
    PB4Button *ls2Button = new PB4Button("ls2");
    ls2Button->setFixedSize(50, 50);
    QGraphicsProxyWidget *proxy3 = scene->addWidget(ls2Button);
    proxy3->setPos(550, 50);
    // Set positions
    nfb->setPos(50, 50);
    fr->setPos(500, 150);
    pb1->setPos(150, 50);
    pb2->setPos(200, 50);
    pb3->setPos(250, 50);
    pb4->setPos(300, 50);
    x1->setPos(350, 250);
    x2->setPos(450, 250);
    x3->setPos(550, 250);
    ls1->setPos(500, 50);
    ls2->setPos(550, 50);
    mcf->setPos(100, 150);
    mcr->setPos(200, 150);
    t1->setPos(300, 150);
    t2->setPos(400, 150);
    ol->setPos(100, 50);
    pl1->setPos(50, 250);
    pl2->setPos(100, 250);
    pl3->setPos(150, 250);
    pl4->setPos(200, 250);
    bz->setPos(250, 250);
    // Add to scene
    scene->addItem(nfb);
    scene->addItem(fr);
    scene->addItem(pb1);
    scene->addItem(pb2);
    scene->addItem(pb3);
    scene->addItem(pb4);
    scene->addItem(x1);
    scene->addItem(x2);
    scene->addItem(x3);
    scene->addItem(ls1);
    scene->addItem(ls2);
    scene->addItem(mcf);
    scene->addItem(mcr);
    scene->addItem(t1);
    scene->addItem(t2);
    scene->addItem(ol);
    scene->addItem(pl1);
    scene->addItem(pl2);
    scene->addItem(pl3);
    scene->addItem(pl4);
    scene->addItem(bz);
    //QTimer timer;// = new QTimer(this);
    frTimer->setInterval(500);
    connect(frTimer, &QTimer::timeout, this, &P7S5::toggleFR);
    connect(ol, &CircuitComponent::pressed, this, &P7S5::handleolPressed);
    // Connect button signals
    connect(pb1, &CircuitComponent::pressed, this, &P7S5::handlePB1Pressed);
    connect(pb2, &CircuitComponent::pressed, this, &P7S5::handlePB2Pressed);
    connect(pb3, &CircuitComponent::pressed, this, &P7S5::handlePB3Pressed);
    connect(pb4Button, &PB4Button::pressed, this, &P7S5::handlePB4Pressed);
    connect(pb4Button, &PB4Button::released, this, &P7S5::handlePB4Released);
    connect(ls1Button, &PB4Button::pressed, this, &P7S5::handlels1Pressed);
    connect(ls1Button, &PB4Button::released, this, &P7S5::handlels1Released);
    connect(ls2Button, &PB4Button::pressed, this, &P7S5::handlels2Pressed);
    connect(ls2Button, &PB4Button::released, this, &P7S5::handlels2Released);
    resetCircuit();
}
void P7S5::handleolPressed() {
    stopMotor();
    if (ol->isActive()) {
        ol->setActive(false);
        fr->setActive(true);
    } else {
        ol->setActive(true);
        fr->setActive(true);
    }
    if (ol->isActive() && fr->isActive()) {
        if (FRBlinking) {
            FRBlinking = false;
            frTimer->stop();
            qDebug() << "FR toggling stopped";
        } else {
            FRBlinking = true;
            frTimer->start();
            qDebug() << "FR toggling started";
        }
    } else {
        FRBlinking = false;
        frTimer->stop();
        fr->setActive(false);
        stopBzSound();
        bz->setOn(false);
        pl4->setOn(false);
        qDebug() << "FR OFF, PL4 OFF, BZ OFF";
    }
}



void P7S5::toggleFR() {
    static bool bzState = false;

    if (!FRBlinking) {
        bz->setOn(false);
        pl4->setOn(true);
        return;
    }

    bzState = !bzState;

    if (bzState) {
        qDebug() << "BZ ON, PL4 OFF";
        onBzLightUp();
        bz->setOn(true);
        pl4->setOn(false);
    } else {
        qDebug() << "BZ OFF, PL4 ON";
        stopBzSound();
        bz->setOn(false);
        pl4->setOn(true);
    }
}

void P7S5::resetCircuit() {
    nfb->setActive(true);
    fr->setActive(false);
    pb1->setActive(false);
    pb2->setActive(false);
    pb3->setActive(false);
    pb4->setActive(false);
    x1->setActive(false);
    x2->setActive(false);
    x3->setActive(false);
    ls1->setActive(false);
    ls2->setActive(false);
    mcf->setActive(false);
    mcr->setActive(false);
    t1->setActive(false);
    t2->setActive(false);
    ol->setActive(false);
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
    pl4->setOn(false);
    bz->setOn(false);  // 確保 BZ 關閉
    FRBlinking = false;
    frTimer->stop();

}

void P7S5::handlePB1Pressed() {
    if (ol->isActive()) x1->setActive(true);
    if (FRBlinking) {
        FRBlinking = false;
        frTimer->stop();
        fr->setActive(false);
        stopBzSound();
        bz->setOn(false);
        pl4->setOn(true);
        qDebug() << "PB1 pressed, FR OFF, PL4 ON, BZ OFF";
    } else {
        qDebug() << "PB1 pressed, but FR is not active";
    }
}


void P7S5::handlePB2Pressed() {
    if (!ol->isActive()) {
        qDebug() << "PB2 Pressed";
        x2->setActive(true);
        mcf->setActive(true);
        pl3->setOn(true);
    }
}
void P7S5::handlePB3Pressed() {
    qDebug() << "PB3 Pressed";
    stopMotor();
}
void P7S5::handlePB4Pressed() {
    pb4->setActive(true);
    if(!ol->isActive()){
        qDebug() << "PB4 Pressed";
        pl3->setOn(true);
    }
}
void P7S5::handlePB4Released() {
    pb4->setActive(false);
    qDebug() << "PB4 Released";
    pl3->setOn(false);
}
void P7S5::handlels1Pressed() {
    if(!ol->isActive() && x2->isActive()){
        qDebug() << "LS1 Pressed";
        t1->setActive(true);
        ls1->setActive(true);
        mcf->setActive(false);
        pl3->setOn(false);
        pl1->setOn(true);
        QTimer::singleShot(2000, this, [this]() {
            if (ls1->isActive()&&!ol->isActive()) { // 確保按鍵仍然被按住
                qDebug() << "LS1 Long Press Triggered";
                x3->setActive(true);
                mcr->setActive(true);
                pl1->setOn(false);
                pl3->setOn(true);

            }
        });
    }
}
void P7S5::handlels1Released() {
    ls1->setActive(false);
    mcr->setActive(false);
    pl3->setOn(false);
    pl2->setOn(true);
    qDebug() << "LS1 Released";
}
void P7S5::handlels2Pressed() {
    if(!ol->isActive() && x3->isActive()){
        ls2->setActive(true);
        t2->setActive(true);
        mcr->setActive(false);
        pl3->setOn(false);
        pl2->setOn(true);
        QTimer::singleShot(2000, this, [this]() {
            if (ls2->isActive()&& !ol->isActive() && x3->isActive()) { // 確保按鍵仍然被按住
                qDebug() << "LS2 Long Press Triggered";

                mcf->setActive(true);
                pl2->setOn(false);
                pl3->setOn(true);

            }
        });
    }
    qDebug() << "LS2 Pressed";
}
void P7S5::handlels2Released() {
    ls2->setActive(false);
    qDebug() << "LS2 Released";
}
void P7S5::stopMotor() {
    qDebug() << "Stopping Motor";
    mcf->setActive(false);
    mcr->setActive(false);
    x1->setActive(false);
    x2->setActive(false);
    x3->setActive(false);
    ls1->setActive(false);
    ls2->setActive(false);
    t1->setActive(false);
    t2->setActive(false);
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
    pl4->setOn(false);
}

void P7S5::onBzLightUp() {
    if (player->playbackState() != QMediaPlayer::PlayingState) {
        qDebug() << "BZ is lighting up! Playing sound.";
        player->play();
    } else {
        qDebug() << "BZ is already playing. Skipping play.";
    }
}

void P7S5::stopBzSound() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        qDebug() << "Stopping BZ sound.";
        disconnect(player, &QMediaPlayer::playbackStateChanged, nullptr, nullptr); // 暫時斷開連接
        player->stop();
        connect(player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState state) {
            if (state == QMediaPlayer::StoppedState && FRBlinking) {
                player->play();
            }
        });
    } else {
        qDebug() << "BZ sound is not playing. Skipping stop.";
    }
    bz->setOn(false); // 確保燈關閉
}
