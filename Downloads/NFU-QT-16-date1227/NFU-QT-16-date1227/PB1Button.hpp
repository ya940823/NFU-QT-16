#ifndef PB1BUTTON_HPP
#define PB1BUTTON_HPP

#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>

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

#endif // PB1BUTTON_HPP
