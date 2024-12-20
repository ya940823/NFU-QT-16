#include "CircuitLogic.hpp"
#include <QDebug>

// 構造函數
CircuitLogic::CircuitLogic(QGraphicsScene *scene) {
    // 初始化電路元件
    nfb = new CircuitComponent("NFB");
    pb1 = new CircuitComponent("PB1");
    ems = new CircuitComponent("EMS");
    thRy = new CircuitComponent("TH-RY");
    x1 = new CircuitComponent("X1");
    x2 = new CircuitComponent("X2");
    x3 = new CircuitComponent("X3");
    mcf = new CircuitComponent("MCF");
    mcr = new CircuitComponent("MCR");

    // 初始化指示燈
    pl1 = new CircuitLamp();
    pl2 = new CircuitLamp();
    pl3 = new CircuitLamp();

    // 將元件添加到場景中
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

    // 配置元件位置
    nfb->setPos(100, 50);
    pb1->setPos(100, 150);
    ems->setPos(100, 250);
    thRy->setPos(100, 350);

    x1->setPos(300, 50);
    x2->setPos(300, 150);
    x3->setPos(300, 250);

    mcf->setPos(500, 50);
    mcr->setPos(500, 150);

    pl1->setPos(700, 50);
    pl2->setPos(700, 150);
    pl3->setPos(700, 250);

    // 設定元件事件
    connect(nfb, &CircuitComponent::clicked, this, &CircuitLogic::handleComponentClick);
    connect(pb1, &CircuitComponent::clicked, this, &CircuitLogic::handleComponentClick);
    connect(ems, &CircuitComponent::clicked, this, &CircuitLogic::handleComponentClick);
    connect(thRy, &CircuitComponent::clicked, this, &CircuitLogic::handleComponentClick);
}

bool NFBison = false, EMSison = false, th_ryison = true;//NFB是否關閉

// 處理元件點擊事件
void CircuitLogic::handleComponentClick(CircuitComponent *component) {
    QString name = component->getName();

    if (name == "NFB") { // NFB在關電時th-ry動作時pl3會亮
        if(!NFBison){
            NFBison = true;
            resetCircuit();
            x1->setActive(true);
            x3->setActive(true);
            pl1->setOn(true);
            mcf->setActive(true);
            qDebug() << "NFB ON: 電源供電，電動機正轉";
        }
        else{
            NFBison = false;
            resetCircuit();
            qDebug() << "NFB OFF: 電源供電，電動機停止";}
    } else if (name == "PB1"&&NFBison) {
        if (x3->isActive()) {  // 使用 isActive()
            // 停止正轉，切換到逆轉
            x3->setActive(false);
            pl1->setOn(false);
            mcf->setActive(false);

            x2->setActive(true);
            pl2->setOn(true);
            mcr->setActive(true);

            qDebug() << "PB1 按下: 切換到逆轉";
        } else if (x2->isActive()) {  // 使用 isActive()
            // 停止逆轉，切換到正轉
            x2->setActive(false);
            pl2->setOn(false);
            mcr->setActive(false);

            x3->setActive(true);
            pl1->setOn(true);
            mcf->setActive(true);

            qDebug() << "PB1 按下: 切換到正轉";
        }
    } else if (name == "EMS"&&NFBison) { //EMS在關電時必須要能動作
        // 緊急停止
        if(!th_ryison){
            if(pl3->isOn) {
                EMSison = false;
                resetCircuit();
                pl3->setOn(false);
            }
            else {
                EMSison = true;
                resetCircuit();
                pl3->setOn(true);
            }
        }
        else if(pl3->isOn) {
            EMSison = false;
            name = "NFB";
            //回到NFB狀態
            resetCircuit();
            x1->setActive(true);
            x3->setActive(true);
            pl1->setOn(true);
            mcf->setActive(true);
            qDebug() << "NFB ON: 電源供電，電動機正轉";
        }
        else{
            EMSison = true;
            resetCircuit();
            pl3->setOn(true);// 緊急停止指示燈亮
            qDebug() << "EMS 按下: 緊急停止所有電路";
        }
    } else if (name == "TH-RY") {
        // 過載保護
        if(th_ryison) {
            th_ryison = false;
            resetCircuit();
        }
        else {
            th_ryison = true;
            x1->setActive(true);
            x3->setActive(true);
            pl1->setOn(true);
            mcf->setActive(true);
        }
        if(EMSison) {
            resetCircuit();
            pl3->setOn(true);
        }else if(pl3->isOn) {
            resetCircuit();
            pl3->setOn(false);
        }
        //pl3->setOn(true);
        qDebug() << "TH-RY 動作: 過載保護觸發";
    }
}

// 重置電路

void CircuitLogic::resetCircuit() {
    // 關閉所有元件和指示燈
    x1->setActive(false);
    x2->setActive(false);
    x3->setActive(false);
    mcf->setActive(false);
    mcr->setActive(false);
    pl1->setOn(false);
    pl2->setOn(false);
    pl3->setOn(false);
}
