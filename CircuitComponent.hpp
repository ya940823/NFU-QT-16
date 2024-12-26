#ifndef CIRCUITCOMPONENT_HPP
#define CIRCUITCOMPONENT_HPP

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
#include <QGraphicsSceneMouseEvent>

// CircuitComponent 類別，表示電路元件
class CircuitComponent : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    // 建構子
    CircuitComponent(const QString &name, QGraphicsItem *parent = nullptr);

    // 設定元件是否啟動
    void setActive(bool state);

    // 獲取元件的啟動狀態
    bool isActive() const;

    // 獲取元件名稱
    QString getName() const;

signals:
    // 按下信號
    void pressed(CircuitComponent *component);

    // 釋放信號
    void released(CircuitComponent *component);

protected:
    // 滑鼠按下事件
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 滑鼠釋放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QString componentName;  // 元件名稱
    bool isActiveState;     // 元件啟動狀態
};


// CircuitLamp 類別，表示電路燈
class CircuitLamp : public QGraphicsEllipseItem {
public:
    // 建構子
    CircuitLamp(const QString &name, QGraphicsItem *parent = nullptr);

    // 設定燈是否開啟
    void setOn(bool state);

    // 獲取燈的開啟狀態
    bool isOn() const;

private:
    QString lampName;  // 燈的名稱
    bool isOnState;    // 燈的開啟狀態
};

#endif // CIRCUITCOMPONENT_HPP
