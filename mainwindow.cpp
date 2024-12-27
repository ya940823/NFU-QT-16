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

    connect(ui->P5, &QPushButton::clicked, this, &MainWindow::onButton1_clicked);
    connect(ui->P6, &QPushButton::clicked, this, &MainWindow::onButton2_clicked);
    connect(ui->P7, &QPushButton::clicked, this, &MainWindow::onButton3_clicked);
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
    srand(time(NULL));
    int number = rand() % 6 + 1; // random number
    qDebug() << number;
    P5CircuitWindow = new class P5CircuitWindow(scene);
    P5CircuitWindow->resetCircuit();
    /*switch (number){
    case 1:
        P5S1 = new class P5S1(scene);
        P5S1->resetCircuit();
        break;
    case 2:
        P5S2 = new class P5S2(scene);
        P5S2->resetCircuit();
        break;
    case 3:
        P5S3 = new class P5S3(scene);
        P5S3->resetCircuit();
        break;
    case 4:
        P5S4 = new class P5S4(scene);
        P5S4->resetCircuit();
        break;
    case 5:
        P5S5 = new class P5S5(scene);
        P5S5->resetCircuit();
        break;
    case 6:
        P5S6 = new class P5S6(scene);
        P5S6->resetCircuit();
        break;
    case 7:
        P5S7 = new class P5S7(scene);
        P5S7->resetCircuit();
        break;
    }*/


    // Create a new QWidget to display the scene
    QWidget *window = new QWidget();
    window->setWindowTitle("P5");

    // Create a QVBoxLayout to manage the layout
    QVBoxLayout *layout = new QVBoxLayout(window);

    // Create a QGraphicsView to display the scene
    QGraphicsView *view = new QGraphicsView(scene, window);
    view->setRenderHint(QPainter::Antialiasing);

    // Add the view to the layout
    layout->addWidget(view);

    // Create buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Create buttons
    QPushButton *button1 = new QPushButton("Open PNG 1", window);
    QPushButton *button2 = new QPushButton("Open PNG 2", window);
    QPushButton *button3 = new QPushButton("Open New Window", window);

    //QString resourcesPath = QDir::currentPath() + "/resources/";
    QString resourcesPath = QCoreApplication::applicationDirPath() + "/resources/";


    // Connect buttons to actions
    connect(button1, &QPushButton::clicked, this, [resourcesPath]() {
        //QString fileName = QFileDialog::getOpenFileName(window, "Open PNG File", "C:\\Users\\user\\Downloads\\NFU-QT-16-date1227\\NFU-QT-16-date1227\\P5circuit.png");
        QString fileName = resourcesPath + "P5circuit.png";
        qDebug() << "Current working directory:" << QDir::currentPath();
        qDebug() << fileName;
        QLabel *label = new QLabel();
        QPixmap pixmap(fileName);
        label->setPixmap(pixmap);
        label->setWindowFlags(Qt::Window);
        label->resize(pixmap.size());
        label->show();
    });

    connect(button2, &QPushButton::clicked, this, [window]() {
        QString fileName = QFileDialog::getOpenFileName(window, "Open PNG File", "", "Images (*.png)");
        if (!fileName.isEmpty()) {
            QLabel *label = new QLabel(window);
            QPixmap pixmap(fileName);
            label->setPixmap(pixmap);
            label->setWindowFlags(Qt::Window);
            label->resize(pixmap.size());
            label->show();
        }
    });

    connect(button3, &QPushButton::clicked, this, [this]() {
        QWidget *newWindow = new QWidget();
        newWindow->setWindowTitle("New Window");
        newWindow->resize(400, 300);
        newWindow->show();
    });
    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    buttonLayout->addWidget(button3);

    // Add the horizontal button layout to the main layout
    layout->addLayout(buttonLayout);
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
