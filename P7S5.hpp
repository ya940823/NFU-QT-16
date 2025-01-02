#ifndef P7S5_HPP
#define P7S5_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "CircuitComponent.hpp"
#include <QMediaPlayer>
#include <QAudioOutput>

class P7S5 : public QObject {
    Q_OBJECT

public:
    explicit P7S5(QGraphicsScene *scene, QObject *parent = nullptr);

    void resetCircuit();
    void onBzLightUp();
    void stopBzSound();
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

private slots:
    void handlePB1Pressed();
    //void handlePB1Released();
    void handlePB2Pressed();
    //void onTimeout();
    void handleolPressed();
    void toggleFR();
    void handlePB3Pressed();
    void handlePB4Pressed();
    void handlePB4Released();
    void handlels1Pressed();
    void handlels1Released();
    void handlels2Pressed();
    void handlels2Released();


private:
    void stopMotor();

    QGraphicsScene *scene;
    QGraphicsView *view;

    CircuitComponent *nfb;
    CircuitComponent *fr;
    CircuitComponent *x1;
    CircuitComponent *x2;
    CircuitComponent *x3;
    CircuitComponent *pb1;
    CircuitComponent *pb2;
    CircuitComponent *pb3;
    CircuitComponent *pb4; // 按下釋放

    CircuitComponent *ls1; // 按下釋放
    CircuitComponent *ls2; // 按下釋放

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
    PB4Button *ls1Button;
    PB4Button *ls2Button;
};

#endif // P6CIRCUITWINDOW_HPP
