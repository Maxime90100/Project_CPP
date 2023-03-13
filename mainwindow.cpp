#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

QPointer<QPushButton> _addButton;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::init();

    QString appTitle = "My TODO List";

    setWindowTitle(appTitle);
    ui->appTitle->setText(appTitle);
    ui->todoAddTitle->setText("Add a Todo");

    _addButton->setText("Add");

    QMessageBox::information(this, tr("Project C++ IUTBM S4"), tr("Welcome to %1 !\nCreated by THEVENEAU Maxime and PERRIN Antoine").arg(appTitle));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    _addButton = ui->todoButton;
    connect(_addButton, &QPushButton::clicked, this, &MainWindow::addTodo);
}

void MainWindow::addTodo(){
    QLineEdit* title = ui->todoTitle;
    QPlainTextEdit* text = ui->todoText;
    QDateEdit* date = ui->todoDate;

    if (title->text().isEmpty() || text->toPlainText().isEmpty() || date->text().isEmpty()) {
        _addButton->setText("You must complete all informations !");
    }
    else {
        _addButton->setText("Todo has been correctly added !");
    }
}

