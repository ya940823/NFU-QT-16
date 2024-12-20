#include "CircuitComponent.hpp"
#include <QGraphicsSceneMouseEvent>

// 電路元件
CircuitComponent::CircuitComponent(const QString &name, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), componentName(name), isActiveState(false) {
    setRect(-30, -15, 60, 30);
    setBrush(Qt::lightGray);
    setPen(QPen(Qt::black));

    QGraphicsTextItem *text = new QGraphicsTextItem(name, this);
    text->setDefaultTextColor(Qt::black);
    text->setPos(-20, -10);
}

void CircuitComponent::setActive(bool state) {
    isActiveState = state;
    setBrush(state ? Qt::green : Qt::lightGray);
}

bool CircuitComponent::isActive() const {  // 新增：Getter 方法
    return isActiveState;
}

QString CircuitComponent::getName() const {
    return componentName;
}

void CircuitComponent::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked(this);
    QGraphicsRectItem::mousePressEvent(event);
}

// 指示燈
CircuitLamp::CircuitLamp(QGraphicsItem *parent)
    : QGraphicsEllipseItem(parent), isOn(false) {
    setRect(-20, -20, 40, 40);
    setBrush(Qt::gray);
    setPen(QPen(Qt::black));
}

void CircuitLamp::setOn(bool state) {
    isOn = state;
    setBrush(state ? Qt::yellow : Qt::gray);
}
