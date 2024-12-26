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

    // 處理 PB1 按下與釋放的插槽
private slots:
    void handlePB1Pressed();  // 無參數版本
    void handlePB1Released(); // 無參數版本
private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    CircuitComponent *nfb;    // NFB (斷路器)
    CircuitComponent *cos1;   // COS1
    CircuitComponent *pb1;    // PB1 按鈕
    CircuitComponent *pb2;    // PB2 按鈕
    CircuitComponent *ems;    // 緊急停止按鈕 (EMS)
    CircuitComponent *thRy;   // TH_RY
    CircuitComponent *mc1;    // 主接觸器 1 (MC1)
    CircuitComponent *mc2;    // 主接觸器 2 (MC2)
    CircuitComponent *mc3;    // 主接觸器 3 (MC3)
    CircuitComponent *t1;     // 計時器 (Timer T1，可能需要額外的類別)
    CircuitLamp *pl1;         // 紅燈 (PL1)
    CircuitLamp *pl2;         // 紅燈 (PL2)
    CircuitLamp *pl3;         // 黃燈 (PL3)
    CircuitLamp *pl4;         // 綠燈 (PL4)
    CircuitLamp *bz;          // 蜂鳴器 (BZ)
};

#endif // P5CIRCUITWINDOW_HPP
