#ifndef P5CIRCUITWINDOW_HPP
#define P5CIRCUITWINDOW_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
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
    CircuitComponent *cos1;
    CircuitComponent *pb1;
    CircuitComponent *pb2;
    CircuitComponent *ems;
    CircuitComponent *thRy;
    CircuitComponent *mc1;
    CircuitComponent *mc2;
    CircuitComponent *mc3;
    CircuitComponent *t1; //timer t1; maybe need new class for timer.
    CircuitLamp *pl1; //red
    CircuitLamp *pl2; //red
    CircuitLamp *pl3; //yellow
    CircuitLamp *pl4; //green
    CircuitLamp *bz; //bz
};

#endif // P5CIRCUITWINDOW_HPP
