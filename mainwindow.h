#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <cstdlib>
#include <QDir>
#include <qdir.h>
#include "P5CircuitWindow.hpp"
#include "P6CircuitWindow.hpp"
#include "P5S1.hpp"
#include "P5S2.hpp"
#include "P5S3.hpp"
#include "P5S4.hpp"
#include "P5S5.hpp"
#include "P5S6.hpp"
#include "P5S7.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButton1_clicked();
    void onButton2_clicked();
    void onButton3_clicked();
    void on_return_to_main_clicked();  // 返回主視窗的槽

private:
    Ui::MainWindow *ui;
    P5CircuitWindow *P5CircuitWindow;
    P6CircuitWindow *P6CircuitWindow;
    P5S4 *P5S4;
    P5S1 *P5S1;
    P5S2 *P5S2;
    P5S3 *P5S3;
    P5S5 *P5S5;
    P5S6 *P5S6;
    P5S7 *P5S7;
};
#endif // MAINWINDOW_H
//正常
//動作說明
//作答
