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
    pb1 = new CircuitComponent("PB1");
    ems = new CircuitComponent("EMS");
    thRy = new CircuitComponent("TH_RY");
    x1 = new CircuitComponent("X1");
    x2 = new CircuitComponent("X2");
    x3 = new CircuitComponent("X3");
    mcf = new CircuitComponent("MCF");
    mcr = new CircuitComponent("MCR");
    pl1 = new CircuitLamp("PL1");
    pl2 = new CircuitLamp("PL2");
    pl3 = new CircuitLamp("PL3");

    // Set positions
    nfb->setPos(50, 50);
    pb1->setPos(150, 50);
    ems->setPos(250, 50);
    thRy->setPos(350, 50);
    x1->setPos(450, 50);
    x2->setPos(550, 50);
    x3->setPos(650, 50);
    mcf->setPos(150, 150);
    mcr->setPos(350, 150);
    pl1->setPos(450, 150);
    pl2->setPos(550, 150);
    pl3->setPos(650, 150);

    // Add to scene
    scene->addItem(nfb);
    scene->addItem(pb1);
    scene->addItem(ems);
    scene->addItem(thRy);
    scene->addItem(x1);
    scene->addItem(x2);
    scene->addItem(x3);
    scene->addItem(mcf);
    scene->addItem(mcr);
    scene->addItem(pl1);
    scene->addItem(pl2);
    scene->addItem(pl3);

    // Connect signals
    connect(pb1, &CircuitComponent::clicked, this, &P5CircuitWindow::handleComponentClick);
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
