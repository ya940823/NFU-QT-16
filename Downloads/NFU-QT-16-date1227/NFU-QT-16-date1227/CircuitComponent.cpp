#include "CircuitComponent.hpp"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

// CircuitComponent 實作
CircuitComponent::CircuitComponent(const QString &name, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), componentName(name), isActiveState(false) {
    setRect(0, 0, 50, 50); // 元件的預設大小
    setBrush(QBrush(Qt::lightGray));
    setPen(QPen(Qt::black));

    QGraphicsTextItem *text = new QGraphicsTextItem(name, this);
    text->setDefaultTextColor(Qt::black);
}

void CircuitComponent::setActive(bool state) {
    isActiveState = state;
    setBrush(state ? QBrush(Qt::green) : QBrush(Qt::lightGray)); // 綠色表示啟動
}

bool CircuitComponent::isActive() const {
    return isActiveState;
}

QString CircuitComponent::getName() const {
    return componentName;
}

// 滑鼠按下事件
 void CircuitComponent::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit pressed (this); // 發出按下信號
     QGraphicsRectItem::mousePressEvent(event); // 確保事件繼續傳遞
 }

// 滑鼠釋放事件
void CircuitComponent::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    emit released(this); // 發出釋放信號
    QGraphicsRectItem::mouseReleaseEvent(event); // 確保事件繼續傳遞
}

// CircuitLamp 實作
CircuitLamp::CircuitLamp(const QString &name, QGraphicsItem *parent)
    : QGraphicsEllipseItem(parent), lampName(name), isOnState(false) {
    setRect(0, 0, 30, 30); // 燈的預設大小
    setBrush(QBrush(Qt::red)); // 紅色表示關閉
    setPen(QPen(Qt::black));
}

void CircuitLamp::setOn(bool state) {
    isOnState = state;
    setBrush(state ? QBrush(Qt::yellow) : QBrush(Qt::red)); // 黃色表示開啟，紅色表示關閉
}

bool CircuitLamp::isOn() const {
    return isOnState;
}
