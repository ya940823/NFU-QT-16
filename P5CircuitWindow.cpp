#include "P5CircuitWindow.hpp"
#include "CircuitComponent.hpp"

#include <QVBoxLayout>
#include <QDebug>

P5CircuitWindow::P5CircuitWindow(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene(scene)
{
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 800, 600);

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
    ems->setPos(250, 50);
    thRy->setPos(300, 50);
    mc1->setPos(100, 150);
    mc2->setPos(200, 150);
    mc3->setPos(300, 150);
    t1->setPos(400, 150);
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
    scene->addItem(ems);
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

    // Connect signals
    connect(pb1, &CircuitComponent::clicked, this, &P5CircuitWindow::handleComponentClick);
    connect(pb2, &CircuitComponent::clicked, this, &P5CircuitWindow::handleComponentClick);
    connect(ems, &CircuitComponent::clicked, this, &P5CircuitWindow::handleComponentClick);
    connect(thRy, &CircuitComponent::clicked, this, &P5CircuitWindow::handleComponentClick);
}

void P5CircuitWindow::handleComponentClick(CircuitComponent *component)
{
    if (component == pb1) {
        qDebug() << "PB1 clicked - Activating circuit.";
        pl1->setOn(true);
    }
}

void P5CircuitWindow::resetCircuit()
{
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
    qDebug() << "Circuit reset.";
}
