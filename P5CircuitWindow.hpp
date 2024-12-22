#ifndef P5CIRCUITWINDOW_HPP
#define P5CIRCUITWINDOW_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class P5CircuitWindow : public QWidget
{
    Q_OBJECT
public:
    explicit P5CircuitWindow(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // P5CIRCUITWINDOW_HPP
