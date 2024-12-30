#include "P6S3.hpp"
#include "CircuitComponent.hpp"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QTimer>

P6S3::P6S3(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene(scene) {
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 800, 600);

    // Initialize components
    nfb = new CircuitComponent("NFB");
    cos1 = new CircuitComponent("COS1");
    pb1 = new CircuitComponent("PB1");
    pb2 = new CircuitComponent("PB2");
    x1 = new CircuitComponent("X1");
    ol1 = new CircuitComponent("OL1");
    ol2 = new CircuitComponent("OL2");
    ol3 = new CircuitComponent("OL3");
    mc1 = new CircuitComponent("MC1");
    mc2 = new CircuitComponent("MC2");
    mc3 = new CircuitComponent("MC3");
    t1 = new CircuitComponent("T1");
    t2 = new CircuitComponent("T2");
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
    ol1->setPos(250, 50);
    ol2->setPos(300, 50);
    ol3->setPos(350, 50);
    x1->setPos(600, 150);
    mc1->setPos(100, 150);
    mc2->setPos(200, 150);
    mc3->setPos(300, 150);
    t1->setPos(400, 150);
    t2->setPos(500, 150);
    pl1->setPos(450, 50);
    pl2->setPos(500, 50);
    pl3->setPos(550, 50);
    pl4->setPos(600, 50);
    bz->setPos(650, 50);

    // Add to scene
    scene->addItem(nfb);
    scene->addItem(cos1);
    scene->addItem(pb1);
    scene->addItem(pb2);
    scene->addItem(x1);
    scene->addItem(mc1);
    scene->addItem(mc2);
    scene->addItem(mc3);
    scene->addItem(t1);
    scene->addItem(t2);
    scene->addItem(pl1);
    scene->addItem(pl2);
    scene->addItem(pl3);
    scene->addItem(pl4);
    scene->addItem(bz);
    scene->addItem(ol1);
    scene->addItem(ol2);
    scene->addItem(ol3);

    // Connect button signals

    // Initialize PB1 button
    /*PB2Button *pb2Button = new PB2Button("PB2");
    pb2Button->setFixedSize(50, 50);

    // Add button to scene using QGraphicsProxyWidget
    QGraphicsProxyWidget *proxy = scene->addWidget(pb1Button);
    proxy->setPos(150, 50);

    connect(pb2, &PB2Button::pressed, this, &P6CircuitWindow::handlePB2Pressed);
    connect(pb2, &PB1Button::released, this, &P6CircuitWindow::handlePB2Released);*/

    // Connect PB2 button signal for motor start
    connect(pb1, &CircuitComponent::pressed, this, &P6S3::handlePB1Clicked);
    connect(pb2, &CircuitComponent::pressed, this, &P6S3::handlePB2Clicked);
    connect(cos1, &CircuitComponent::pressed, this, &P6S3::handlecos1Pressed);

    // Connect OL button signal for motor start
    connect(ol1, &CircuitComponent::pressed, this, &P6S3::handleol1Pressed);
    connect(ol2, &CircuitComponent::pressed, this, &P6S3::handleol2Pressed);
    connect(ol3, &CircuitComponent::pressed, this, &P6S3::handleol3Pressed);

    resetCircuit();
}

void P6S3::resetCircuit() {
    nfb->setActive(true);
    pb1->setActive(false);
    pb2->setActive(false);
    x1->setActive(false);
    mc1->setActive(false);
    mc2->setActive(false);
    mc3->setActive(false);
    t1->setActive(false);
    t2->setActive(false);
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
    pl4->setOn(false);
    bz->setOn(false);
}

void P6S3::handlePB1Clicked() {
    qDebug() << "PB1 Pressed";
    if (pb1->isActive()) pb1->setActive(false);
    else pb1->setActive(true);
    if(!ol1->isActive() && !ol2->isActive() && !ol3->isActive() && !pb2->isActive()) {
        mc1->setActive(true);
        pl1->setOn(true);
        t1->setActive(true);
        QTimer::singleShot(2000, this, [this]() {
            if(!ol1->isActive() && !ol2->isActive() && !ol3->isActive() && !pb2->isActive()) {
                mc2->setActive(true);
                pl2->setOn(true);
            }
            t1->setActive(false);
            t2->setActive(true);
            QTimer::singleShot(2000, this, [this]() {
                if(!ol1->isActive() && !ol2->isActive() && !ol3->isActive() && !pb2->isActive()) {
                    mc3->setActive(true);
                    pl4->setOn(true);
                }
                t2->setActive(false);
            });
        });
    }
}

void P6S3::handlePB2Clicked() {
    qDebug() << "PB2 Pressed";
    if (pb2->isActive()) pb2->setActive(false);
    else pb2->setActive(true);
    if(!ol1->isActive() && !ol2->isActive() && !ol3->isActive()) {
        mc1->setActive(false);
        pl1->setOn(false);
    }
}

void P6S3::stopMotor() {
    qDebug() << "Stopping Motor";
    mc1->setActive(false);
    mc2->setActive(false);
    mc3->setActive(false);
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
    pl4->setOn(false);
    bz->setOn(false);
}

void P6S3::handlecos1Pressed() {
    if (cos1->isActive()) cos1->setActive(false);
    else cos1->setActive(true);
    if (ol1->isActive() || ol2->isActive() || ol3->isActive()) {
        if (cos1->isActive()) {
            bz->setOn(true);
            pl3->setOn(false);
        } else {
            pl3->setOn(true);
            bz->setOn(false);
        }
    }
}

void P6S3::handleol1Pressed() {
    qDebug() << "TH_RY Triggered: Stopping motor and handling COS1 behavior";
    stopMotor();

    if (ol1->isActive())ol1->setActive(false); //thry true: up
    else ol1->setActive(true);
    if(cos1->isActive() && ol1->isActive()){ //cos1 true:1, cos1 false:2
        //thry up
        resetCircuit();
        bz->setOn(true);
        pl3->setOn(false);
    }
    else if(!cos1->isActive() && ol1->isActive()){
        //thry up
        resetCircuit();
        bz->setOn(false);
        pl3->setOn(true);
    }
    else if(cos1->isActive() && !ol1->isActive()){
        bz->setOn(false);
        pl3->setOn(false);
    }
    else if(!cos1->isActive() && !ol1->isActive()){
        bz->setOn(false);
        pl3->setOn(false);
    }
}

void P6S3::handleol2Pressed() {
    qDebug() << "TH_RY Triggered: Stopping motor and handling COS1 behavior";
    stopMotor();

    if (ol2->isActive())ol2->setActive(false); //thry true: up
    else ol2->setActive(true);
    if(cos1->isActive() && ol2->isActive()){ //cos1 true:1, cos1 false:2
        //thry up
        resetCircuit();
        bz->setOn(true);
        pl3->setOn(false);
    }
    else if(!cos1->isActive() && ol2->isActive()){
        //thry up
        resetCircuit();
        bz->setOn(false);
        pl3->setOn(true);
    }
    else if(cos1->isActive() && !ol2->isActive()){
        bz->setOn(false);
        pl3->setOn(false);
    }
    else if(!cos1->isActive() && !ol2->isActive()){
        bz->setOn(false);
        pl3->setOn(false);
    }
}

void P6S3::handleol3Pressed() {
    qDebug() << "TH_RY Triggered: Stopping motor and handling COS1 behavior";
    stopMotor();

    if (ol3->isActive())ol3->setActive(false); //thry true: up
    else ol3->setActive(true);
    if(cos1->isActive() && ol3->isActive()){ //cos1 true:1, cos1 false:2
        //thry up
        resetCircuit();
        bz->setOn(true);
        pl3->setOn(false);
    }
    else if(!cos1->isActive() && ol3->isActive()){
        //thry up
        resetCircuit();
        bz->setOn(false);
        pl3->setOn(true);
    }
    else if(cos1->isActive() && !ol3->isActive()){
        bz->setOn(false);
        pl3->setOn(false);
    }
    else if(!cos1->isActive() && !ol3->isActive()){
        bz->setOn(false);
        pl3->setOn(false);
    }
}
