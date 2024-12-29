#include "P7CircuitWindow.hpp"
#include "CircuitComponent.hpp"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QTimer>

P7CircuitWindow::P7CircuitWindow(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene(scene) {
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 800, 600);

    // Initialize components
    nfb = new CircuitComponent("NFB");
    fr = new CircuitComponent("FR");
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

    // Set positions
    nfb->setPos(50, 50);
    fr->setPos(100, 50);
    pb1->setPos(150, 50);
    pb2->setPos(200, 50);
    pb3->setPos(250, 50);
    pb4->setPos(300, 50);
    x1->setPos(350, 50);
    x2->setPos(400, 50);
    x3->setPos(450, 50);
    ls1->setPos(500, 50);
    ls2->setPos(550, 50);
    mcf->setPos(100, 150);
    mcr->setPos(200, 150);
    t1->setPos(300, 150);
    t2->setPos(400, 150);
    ol->setPos(500, 150);
    pl1->setPos(450, 200);
    pl2->setPos(500, 200);
    pl3->setPos(550, 200);
    pl4->setPos(600, 200);

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

    // Connect button signals
    connect(pb1, &CircuitComponent::pressed, this, &P7CircuitWindow::handlePB1Pressed);
    connect(pb2, &CircuitComponent::pressed, this, &P7CircuitWindow::handlePB2Pressed);

    resetCircuit();
}

void P7CircuitWindow::resetCircuit() {
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
}

void P7CircuitWindow::handlePB1Pressed() {
    qDebug() << "PB1 Pressed";
    mcf->setActive(true);
    pl1->setOn(true);
}

void P7CircuitWindow::handlePB2Pressed() {
    qDebug() << "PB2 Pressed";
    mcr->setActive(true);
    pl2->setOn(true);
}


void P7CircuitWindow::stopMotor() {
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
    ol->setActive(false);
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
    pl4->setOn(false);
}
