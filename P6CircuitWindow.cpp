#include "P6CircuitWindow.hpp"
#include "CircuitComponent.hpp"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QTimer>

P6CircuitWindow::P6CircuitWindow(QGraphicsScene *scene, QObject *parent)
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
    x1->setPos(250, 50);
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

    // Initialize PB1 button
    PB1Button *pb1Button = new PB1Button("PB1");
    pb1Button->setFixedSize(50, 50);

    // Add button to scene using QGraphicsProxyWidget
    QGraphicsProxyWidget *proxy = scene->addWidget(pb1Button);
    proxy->setPos(150, 50);

    // Connect button signals
    connect(pb1Button, &PB1Button::pressed, this, &P6CircuitWindow::handlePB1Pressed);
    connect(pb1Button, &PB1Button::released, this, &P6CircuitWindow::handlePB1Released);

    // Connect PB2 button signal for motor start
    connect(pb2, &CircuitComponent::pressed, this, &P6CircuitWindow::handlePB2Pressed);
    connect(cos1, &CircuitComponent::pressed, this, &P6CircuitWindow::handlecos1Pressed);

    // Reset circuit
    resetCircuit();
}

void P6CircuitWindow::resetCircuit() {
    nfb->setActive(true);
    cos1->setActive(false);
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

void P6CircuitWindow::handlePB1Pressed() {
    qDebug() << "PB1 Pressed";
}

void P6CircuitWindow::handlePB1Released() {
    qDebug() << "PB1 Released";
}

void P6CircuitWindow::handlePB2Pressed() {
    qDebug() << "PB2 Pressed";
}

void P6CircuitWindow::handlecos1Pressed() {
    qDebug() << "COS1 Pressed";
}

void P6CircuitWindow::stopMotor() {
    qDebug() << "Stopping Motor";
}
