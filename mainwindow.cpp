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
    int Randomnumber = rand() % 6 + 1; // random number
    //qDebug() << Randomnumber;
    //P5CircuitWindow = new class P5CircuitWindow(scene);
    //P5CircuitWindow->resetCircuit();
    switch (Randomnumber){
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
    }


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
    QPushButton *button1 = new QPushButton("P5電路圖", window);
    QPushButton *button2 = new QPushButton("P5動作說明", window);
    QPushButton *button3 = new QPushButton("作答", window);

    QString resourcesPath = QDir::currentPath();
    QString curPath = resourcesPath.section('/', 0, -3) + "/resources/";
    //QString resourcesPath = QCoreApplication::applicationDirPath() + "/resources/";
    //QString resourcesPath = QString(__FILE__).section('/', 0, -2) + "/resources/";

    connect(button1, &QPushButton::clicked, this, [curPath]() {
        QString fileName = curPath + "P5circuit.png";
        qDebug() << "Current working directory:" << QDir::currentPath();
        qDebug() << fileName;
        QLabel *label = new QLabel();
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            label->setScaledContents(true); // Enable scaling
            label->setPixmap(pixmap);
        }
        label->setWindowFlags(Qt::Window);
        //label->resize(pixmap.size());
        label->resize(800, 600);
        label->setWindowTitle("P5電路圖");
        //label->setFixedSize(800, 600);
        label->show();
    });

    connect(button2, &QPushButton::clicked, this, [curPath]() {
        QString fileName = curPath + "P5work.png";
        if (!fileName.isEmpty()) {
            QLabel *label = new QLabel();
            QPixmap pixmap(fileName);
            if (!pixmap.isNull()) {
                label->setScaledContents(true); // Enable scaling
                label->setPixmap(pixmap);
            }
            label->setWindowFlags(Qt::Window);
            //label->resize(pixmap.size());
            label->resize(800, 600);
            label->setWindowTitle("P5動作說明");
            label->show();
        }
    });

    connect(button3, &QPushButton::clicked, this, [this, curPath, Randomnumber]() {
        // Create a new window
        QWidget *newWindow = new QWidget();
        newWindow->setWindowTitle("作答");

        // Create layout for the new window
        QVBoxLayout *newLayout = new QVBoxLayout(newWindow);

        // Add a QLabel to display the PNG
        QLabel *imageLabel = new QLabel(newWindow);
        QString fileName = curPath + "P5ans.png"; // Specify the path to the PNG file
        QPixmap pixmap(fileName);
        imageLabel->setPixmap(pixmap);
        imageLabel->setAlignment(Qt::AlignCenter);

        // Add a QLineEdit for text input
        QLineEdit *lineEdit = new QLineEdit(newWindow);
        lineEdit->setPlaceholderText("Enter text here...");

        // Add a QPushButton to submit the text
        QPushButton *submitButton = new QPushButton("Submit", newWindow);
        connect(submitButton, &QPushButton::clicked, this, [lineEdit, newWindow, Randomnumber]() {
            QString inputText = lineEdit->text();
            qDebug() << "Submitted Text:" << inputText;

            // Close the original window
            newWindow->close();

            // Create a new confirmation window
            QWidget *confirmationWindow = new QWidget();
            confirmationWindow->setWindowTitle("Confirmation");

            // Add a layout to the confirmation window
            QVBoxLayout *confirmationLayout = new QVBoxLayout(confirmationWindow);

            // Add a label to display the submitted text
            std::string str = inputText.toStdString();
            //QLabel *confirmationLabel = new QLabel(confirmText, confirmationWindow);
            QLabel *confirmationLabel = new QLabel(confirmationWindow);
            if(str == "S" + std::to_string(Randomnumber) || str == "s" + std::to_string(Randomnumber) || str == std::to_string(Randomnumber)) {
                confirmationLabel->setText("Correct Answer!");
                confirmationLabel->setStyleSheet("color: green; font-size: 24px; font-weight: bold;");
            }else{
                confirmationLabel->setText("Wrong Answer.");
                confirmationLabel->setStyleSheet("color: red; font-size: 24px; font-weight: bold;");
            }
            confirmationLabel->setAlignment(Qt::AlignCenter);

            // Add the label to the layout
            confirmationLayout->addWidget(confirmationLabel);

            // Set layout and show the confirmation window
            confirmationWindow->setLayout(confirmationLayout);
            confirmationWindow->resize(300, 200);
            confirmationWindow->show();
        });

        // Add widgets to the layout
        newLayout->addWidget(imageLabel);
        newLayout->addWidget(lineEdit);
        newLayout->addWidget(submitButton);

        // Set layout and show the window
        newWindow->setLayout(newLayout);
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
