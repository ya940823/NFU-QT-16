#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 使用 Qt::UniqueConnection 來確保每個按鈕只連接一次
    connect(ui->button1, &QPushButton::pressed, this, &MainWindow::on_button1_clicked);
    connect(ui->button2, &QPushButton::pressed, this, &MainWindow::on_button2_clicked);
    connect(ui->button3, &QPushButton::pressed, this, &MainWindow::on_button3_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_clicked()
{
    // 顯示訊息框
    QWidget *newWindow1 = new QWidget();
    newWindow1->setWindowTitle("新視窗 1");
    newWindow1->resize(400, 300);

    // 創建返回主頁的按鈕
    QPushButton *returnButton = new QPushButton("返回主頁", newWindow1);
    returnButton->setGeometry(150, 250, 100, 40); // 設定返回按鈕的位置和大小
    connect(returnButton, &QPushButton::clicked, this, &MainWindow::on_return_to_main_clicked);

    newWindow1->show();

    // 關閉主視窗
    this->close();
}

void MainWindow::on_button2_clicked()
{
    // 打開第二個新視窗
    QWidget *newWindow2 = new QWidget();
    newWindow2->setWindowTitle("新視窗 2");
    newWindow2->resize(400, 300);

    // 創建返回主頁的按鈕
    QPushButton *returnButton = new QPushButton("返回主頁", newWindow2);
    returnButton->setGeometry(150, 250, 100, 40); // 設定返回按鈕的位置和大小
    connect(returnButton, &QPushButton::clicked, this, &MainWindow::on_return_to_main_clicked);

    newWindow2->show();

    // 關閉主視窗
    this->close();
}

void MainWindow::on_button3_clicked()
{
    // 打開第三個新視窗
    QWidget *newWindow3 = new QWidget();
    newWindow3->setWindowTitle("新視窗 3");
    newWindow3->resize(400, 300);

    // 創建返回主頁的按鈕
    QPushButton *returnButton = new QPushButton("返回主頁", newWindow3);
    returnButton->setGeometry(150, 250, 100, 40); // 設定返回按鈕的位置和大小
    connect(returnButton, &QPushButton::clicked, this, &MainWindow::on_return_to_main_clicked);

    newWindow3->show();

    // 關閉主視窗
    this->close();
}

void MainWindow::on_return_to_main_clicked()
{
    // 重新顯示主視窗
    this->show();
    // 關閉當前新視窗
    QWidget *currentWindow = qobject_cast<QWidget*>(sender()->parent());
    if (currentWindow) {
        currentWindow->close();
    }
}
