#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

QVariant _addButton;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString appTitle = "My TODO List";

    setWindowTitle(appTitle);
    ui->appTitle->setText(appTitle);
    ui->todoAddTitle->setText("Add a Todo");

    _addButton.setValue(ui->todoButton);
    QPushButton* button = ui->todoButton;
    button->setText("Add");
    connect(button, &QPushButton::clicked, this, &MainWindow::button_clicked);

    QMessageBox::information(this, tr("Project C++ IUTBM S4"), tr("Welcome to %1 !\nCreated by THEVENEAU Maxime and PERRIN Antoine").arg(appTitle));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked(){
    QPushButton* button = _addButton.value<QPushButton*>();
    button->setText("Todo has been correctly added !");
}
