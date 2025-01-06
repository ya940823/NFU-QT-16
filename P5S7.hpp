#ifndef P5S7_H
#define P5S7_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "CircuitComponent.hpp"

class P5S7 : public QObject {
    Q_OBJECT

public:
    explicit P5S7(QGraphicsScene *scene, QObject *parent = nullptr);

    void resetCircuit();

private slots:
    void handlePB1Pressed();
    void handlePB1Released();
    void handlePB2Pressed();
    void handlecos1Pressed();
    void handleTHRYTriggered();

private:
    void stopMotor();
    void onBzLightUp();
    void stopBzSound();

    QGraphicsScene *scene;
    QGraphicsView *view;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

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
