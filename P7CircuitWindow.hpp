#ifndef P7CIRCUITWINDOW_HPP
#define P7CIRCUITWINDOW_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class P7CircuitWindow : public QWidget
{
    Q_OBJECT
public:
    explicit P7CircuitWindow(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // P7CIRCUITWINDOW_HPP
