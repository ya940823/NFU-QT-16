#ifndef P5CIRCUITWINDOW_HPP
#define P5CIRCUITWINDOW_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "CircuitComponent.hpp"

class P5CircuitWindow : public QObject {
    Q_OBJECT

public:
    explicit P5CircuitWindow(QGraphicsScene *scene, QObject *parent = nullptr);

    void resetCircuit();

private slots:
    void handlePB1Pressed();
    void handlePB1Released();
    void handlePB2Pressed();
    void handlecos1Pressed();
    void handleTHRYTriggered();

private:
    void stopMotor();

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
    CircuitComponent *t1;

    CircuitLamp *pl1;
    CircuitLamp *pl2;
    CircuitLamp *pl3;
    CircuitLamp *pl4;
    CircuitLamp *bz;
};

#endif // P5CIRCUITWINDOW_HPP
