#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
};
#endif // MAINWINDOW_H
