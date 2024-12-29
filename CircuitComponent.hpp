#ifndef CIRCUITCOMPONENT_HPP
#define CIRCUITCOMPONENT_HPP

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>
#include <QCoreApplication>
#include <QTimer>

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

class PB1Button : public QPushButton {
    Q_OBJECT

public:
    explicit PB1Button(const QString &text, QWidget *parent = nullptr) : QPushButton(text, parent) {}

signals:
    void pressed();  // 按下信號
    void released(); // 釋放信號

protected:
    // 處理滑鼠按下事件
    void mousePressEvent(QMouseEvent *event) override {
        qDebug() << "PB1 Mouse Pressed";
        emit pressed();
        QPushButton::mousePressEvent(event); // 確保基類行為正常
    }

    // 處理滑鼠釋放事件
    void mouseReleaseEvent(QMouseEvent *event) override {
        qDebug() << "PB1 Mouse Released";
        emit released();
        QPushButton::mouseReleaseEvent(event); // 確保基類行為正常
    }
};

class Framework : public QObject {
    Q_OBJECT

public:
    QTimer* timer;
    Framework(QObject* parent = nullptr) : QObject(parent) {
        // 創建 QTimer
        timer = new QTimer(this);

        // 連接定時器的 timeout 信號到自定義槽
        connect(timer, &QTimer::timeout, this, &Framework::onTimeout);

        // 設置定時器間隔為 500 毫秒
        timer->setInterval(500);

        // 啟動定時器
        timer->start();
    }

    ~Framework() {
        // QTimer 將由父類自動管理和釋放
    }

public slots:
    void onTimeout() {
        // 這是定時觸發的函數
        qDebug() << "自定義函數觸發，每 0.5 秒執行一次";
    }

private:
    //QTimer* timer;  // QTimer 的指針
};

#endif // CIRCUITCOMPONENT_HPP
