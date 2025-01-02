#ifndef P6S5_HPP
#define P6S5_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "CircuitComponent.hpp"

class P6S5 : public QObject {
    Q_OBJECT

public:
    explicit P6S5(QGraphicsScene *scene, QObject *parent = nullptr);

    void resetCircuit();

private slots:
    void handlePB1Clicked();
    //void handlePB1Released();
    //void handlePB2Pressed();
    //void handlePB2Released();
    void handlePB2Clicked();
    //void handleolPressed();
    void handlecos1Pressed();
    void handleol1Pressed();
    void handleol2Pressed();
    void handleol3Pressed();

private:
    void stopMotor();

    QGraphicsScene *scene;
    QGraphicsView *view;

    CircuitComponent *nfb;
    CircuitComponent *cos1;
    CircuitComponent *x1;
    CircuitComponent *pb1;
    CircuitComponent *pb2;

    CircuitComponent *ol1;
    CircuitComponent *ol2;
    CircuitComponent *ol3;
    CircuitComponent *mc1;
    CircuitComponent *mc2;
    CircuitComponent *mc3;
    CircuitComponent *t1;
    CircuitComponent *t2;

    CircuitLamp *pl1;
    CircuitLamp *pl2;
    CircuitLamp *pl3;
    CircuitLamp *pl4;
    CircuitLamp *bz;
};

#endif // P6CIRCUITWINDOW_HPP
