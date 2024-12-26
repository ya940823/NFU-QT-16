#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::onButton1_clicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::onButton2_clicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::onButton3_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButton1_clicked()
{
    // Create a new scene
    QGraphicsScene *scene = new QGraphicsScene(this);

    // Initialize P5CircuitWindow with the scene
    p5CircuitWindow = new P5CircuitWindow(scene);

    // Optionally interact with the P5CircuitWindow here
    p5CircuitWindow->resetCircuit(); // Reset the circuit state

    // Create a new QWidget to display the scene
    QWidget *window = new QWidget();
    window->setWindowTitle("P5 Circuit Simulation");

    // Create a QVBoxLayout to manage the layout
    QVBoxLayout *layout = new QVBoxLayout(window);

    // Create a QGraphicsView to display the scene
    QGraphicsView *view = new QGraphicsView(scene, window);
    view->setRenderHint(QPainter::Antialiasing);

    // Add the view to the layout
    layout->addWidget(view);

    // Set layout for the window
    window->setLayout(layout);
    window->resize(800, 600);

    // Show the window
    window->show();

    // Close the main window
    this->close();
}

void MainWindow::onButton2_clicked()
{
    // Placeholder for button 2 logic
}

void MainWindow::onButton3_clicked()
{
    // Placeholder for button 3 logic
}

void MainWindow::on_return_to_main_clicked()
{
    // Reopen main window
    this->show();
    // Close current child window
    QWidget *currentWindow = qobject_cast<QWidget*>(sender()->parent());
    if (currentWindow) {
        currentWindow->close();
    }
}
