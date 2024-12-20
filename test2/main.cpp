#include <QApplication>
#include <QGraphicsView>
#include "CircuitLogic.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 創建場景
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);

    // 電路邏輯控制
    CircuitLogic circuit(&scene);

    // 配置視窗
    view.setSceneRect(0, 0, 800, 600);
    view.setWindowTitle("大型電路模擬");
    view.show();

    return app.exec();
}
