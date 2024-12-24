#ifndef P5CIRCUITWINDOW_HPP
#define P5CIRCUITWINDOW_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
//#include "CircuitLogic.hpp"
#include "CircuitComponent.hpp"

class P5CircuitWindow : public QObject
{
    Q_OBJECT

public:
    explicit P5CircuitWindow(QGraphicsScene *scene, QObject *parent = nullptr);

    void resetCircuit(); // Reset circuit components

private slots:
//public slots:
    void handleComponentClick(CircuitComponent *component);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    CircuitComponent *nfb;
    CircuitComponent *pb1;
    CircuitComponent *ems;
    CircuitComponent *thRy;
    CircuitComponent *x1;
    CircuitComponent *x2;
    CircuitComponent *x3;
    CircuitComponent *mcf;
    CircuitComponent *mcr;
    CircuitLamp *pl1;
    CircuitLamp *pl2;
    CircuitLamp *pl3;
};

#endif // P5CIRCUITWINDOW_HPP
