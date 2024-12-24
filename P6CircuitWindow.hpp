#ifndef P6CIRCUITWINDOW_HPP
#define P6CIRCUITWINDOW_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class P6CircuitWindow : public QWidget
{
    Q_OBJECT
public:
    explicit P6CircuitWindow(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // P6CIRCUITWINDOW_HPP
