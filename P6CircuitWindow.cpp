#include "P6CircuitWindow.hpp"
#include <QVBoxLayout>

P6CircuitWindow::P6CircuitWindow(QWidget *parent)
    : QWidget(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this))
{
    // 配置場景和視圖
    view->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 800, 600);

    // 配置視窗
    this->setWindowTitle("P6 電路模擬");
    this->resize(800, 600);

    // 使用布局管理器
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    // 添加不同的電路邏輯
    scene->addText("This is P6 Circuit Window!");
}
