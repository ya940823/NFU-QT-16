#ifndef P7CIRCUITWINDOW_HPP
#define P7CIRCUITWINDOW_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "CircuitComponent.hpp"

class P7CircuitWindow : public QObject {
    Q_OBJECT

public:
    explicit P7CircuitWindow(QGraphicsScene *scene, QObject *parent = nullptr);

    void resetCircuit();

private slots:
    void handlePB1Pressed();
    //void handlePB1Released();
    void handlePB2Pressed();
    //void onTimeout();
    void handleolPressed();
    void toggleFR();

private:
    void stopMotor();

    QGraphicsScene *scene;
    QGraphicsView *view;

    CircuitComponent *nfb;
    CircuitComponent *fr; // ?
    CircuitComponent *x1;
    CircuitComponent *x2;
    CircuitComponent *x3;
    CircuitComponent *pb1;
    CircuitComponent *pb2;
    CircuitComponent *pb3;
    CircuitComponent *pb4;

    CircuitComponent *ls1; // ?
    CircuitComponent *ls2; // ?
    CircuitComponent *mcf;
    CircuitComponent *mcr;
    CircuitComponent *t1;
    CircuitComponent *t2;
    CircuitComponent *ol;

    CircuitLamp *pl1;
    CircuitLamp *pl2;
    CircuitLamp *pl3;
    CircuitLamp *pl4;
    CircuitLamp *bz;
    QTimer *frTimer;
    bool FRBlinking;
};

#endif // P6CIRCUITWINDOW_HPP
