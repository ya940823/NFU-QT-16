#include "CircuitComponent.hpp"
#include <QPainter>
#include <QDebug>

// CircuitComponent Implementation
CircuitComponent::CircuitComponent(const QString &name, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), componentName(name), isActiveState(false) {
    setRect(0, 0, 50, 50); // Default size of the component
    setBrush(QBrush(Qt::lightGray));
    setPen(QPen(Qt::black));

    QGraphicsTextItem *text = new QGraphicsTextItem(name, this);
    text->setDefaultTextColor(Qt::black);
    //text->setPos(-20, -10);
}

void CircuitComponent::setActive(bool state) {
    isActiveState = state;
    setBrush(state ? QBrush(Qt::green) : QBrush(Qt::lightGray));
}

bool CircuitComponent::isActive() const {
    return isActiveState;
}

QString CircuitComponent::getName() const {
    return componentName;
}

void CircuitComponent::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked(this);
    QGraphicsRectItem::mousePressEvent(event);
}

// CircuitLamp Implementation
CircuitLamp::CircuitLamp(const QString &name, QGraphicsItem *parent)
    : QGraphicsEllipseItem(parent), lampName(name), isOnState(false) {
    setRect(0, 0, 30, 30); // Default size of the lamp
    setBrush(QBrush(Qt::red));
    setPen(QPen(Qt::black));
}

void CircuitLamp::setOn(bool state) {
    isOnState = state;
    setBrush(state ? QBrush(Qt::yellow) : QBrush(Qt::red));
}

bool CircuitLamp::isOn() const {
    return isOnState;
}
