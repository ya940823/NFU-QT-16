#ifndef CIRCUITCOMPONENT_HPP
#define CIRCUITCOMPONENT_HPP

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QPen>

// 繼電器類別
class CircuitComponent : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    explicit CircuitComponent(const QString &name, QGraphicsItem *parent = nullptr);

    void setActive(bool state);
    QString getName() const;

signals:
    void clicked(CircuitComponent *component);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QString componentName;
    bool isActive;
};

// 指示燈類別
class CircuitLamp : public QGraphicsEllipseItem {
public:
    explicit CircuitLamp(QGraphicsItem *parent = nullptr);

    void setOn(bool state);

private:
    bool isOn;
};

#endif // CIRCUITCOMPONENT_HPP
