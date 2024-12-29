#include "P7CircuitWindow.hpp"
#include "CircuitComponent.hpp"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QTimer>

P7CircuitWindow::P7CircuitWindow(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene(scene),frTimer(new QTimer(this)),FRBlinking(false) {
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 800, 600);

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

    // Set positions
    nfb->setPos(50, 50);
    fr->setPos(500, 150);
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
    connect(frTimer, &QTimer::timeout, this, &P7CircuitWindow::toggleFR);
    connect(fr, &CircuitComponent::pressed, this, &P7CircuitWindow::handleFRPressed);
    // Connect button signals
    connect(pb1, &CircuitComponent::pressed, this, &P7CircuitWindow::handlePB1Pressed);
    connect(pb2, &CircuitComponent::pressed, this, &P7CircuitWindow::handlePB2Pressed);
    resetCircuit();
}
void P7CircuitWindow::handleFRPressed() {
    if (FRBlinking) {
        FRBlinking = false;
        frTimer->stop();
        qDebug() << "FR toggling stopped";
    } else {
        FRBlinking = true;
        frTimer->start();
        qDebug() << "FR toggling started";
    }

    fr->setActive(true);
}



void P7CircuitWindow::toggleFR() {
    static bool bzState = false;

    if (!FRBlinking) {
        // 確保在停止時不再切換狀態
        bz->setOn(false);
        pl4->setOn(true);
        return;
    }

    bzState = !bzState;

    if (bzState) {
        qDebug() << "BZ ON, PL4 OFF";
        bz->setOn(true);
        pl4->setOn(false);
    } else {
        qDebug() << "BZ OFF, PL4 ON";
        bz->setOn(false);
        pl4->setOn(true);
    }
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
    bz->setOn(false);  // 確保 BZ 關閉
    FRBlinking = false;
    frTimer->stop();

}

void P7CircuitWindow::handlePB1Pressed() {
    if (FRBlinking) {
        FRBlinking = false;
        frTimer->stop();
        fr->setActive(false);  // 關閉 FR
        bz->setOn(false);      // 確保 BZ 關閉
        pl4->setOn(true);      // 打開 PL4
        qDebug() << "PB1 pressed, FR OFF, PL4 ON, BZ OFF";
    } else {
        qDebug() << "PB1 pressed, but FR is not active";
    }
}

void P7CircuitWindow::handlePB2Pressed() {
    qDebug() << "PB2 Pressed";
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
