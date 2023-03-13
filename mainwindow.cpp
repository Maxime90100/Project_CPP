#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString appTitle = "My TODO List";

    setWindowTitle(appTitle);
    ui->appTitle->setText(appTitle);
    QMessageBox::information(this, tr("Project C++ IUTBM S4"), tr("Welcome to %1 !\nCreated by THEVENEAU Maxime and PERRIN Antoine").arg(appTitle));
}

MainWindow::~MainWindow()
{
    delete ui;
}
