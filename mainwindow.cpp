#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "todolistitem.h"
#include <QMessageBox>
#include <QTimer>

// TODO LIST
QPointer<QListWidget > _todoList;

// ADD TODO
QPointer<QLineEdit> _todoAddTitle;
QPointer<QPlainTextEdit> _todoAddText;
QPointer<QDateEdit> _todoAddDate;
QPointer<QPushButton> _todoAddButton;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::init();

    QString appTitle = "My TODO List";
    setWindowTitle(appTitle);
    ui->appTitle->setText(appTitle);
    QMessageBox::information(this, tr("Project C++ IUTBM S4"), tr("Welcome to %1 !\nCreated by THEVENEAU Maxime and PERRIN Antoine").arg(appTitle));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    // TODO LIST
    ui->todoListTitle->setText("Todo list");
    _todoList = ui->todoList;

    // ADD TODO
     ui->todoAddLayoutTitle->setText("Add a Todo");

     _todoAddButton = ui->todoAddButton;
     _todoAddButton->setText("Add");
     connect(_todoAddButton, &QPushButton::clicked, this, &MainWindow::addTodo);

    _todoAddTitle = ui->todoAddTitle;
    connect(_todoAddTitle, &QLineEdit::textChanged, this, &MainWindow::updateForm);

    _todoAddText = ui->todoAddText;
    connect(_todoAddText, &QPlainTextEdit::textChanged, this, &MainWindow::updateForm);

    _todoAddDate = ui->todoAddDate;
    connect(_todoAddDate, &QDateEdit::dateChanged, this, &MainWindow::updateForm);
    _todoAddDate->setDate(QDate::currentDate());
}

void MainWindow::addTodo(){
    if (_todoAddTitle->text().isEmpty() || _todoAddText->toPlainText().isEmpty()) {
        // ERROR
        _todoAddButton->setText("You must complete all informations !");
        _todoAddButton->setStyleSheet("background-color: red; color: white");
    }
    else {
        // SUCCESS
        _todoAddButton->setText("Todo has been correctly added !");
        _todoAddButton->setStyleSheet("background-color: green; color: white");

        // Add TODO
        TodoListItem *itemWidget = new TodoListItem(_todoList);
        itemWidget->setTitle(_todoAddTitle->text());
        itemWidget->setText(_todoAddText->toPlainText());
        itemWidget->setDate(_todoAddDate->date());
        QListWidgetItem* newItem = new QListWidgetItem();
        newItem->setSizeHint(itemWidget->sizeHint());
        _todoList->addItem(newItem);
        _todoList->setItemWidget(newItem, itemWidget);

        QTimer::singleShot(2000, [](){
            // Clear Form
            _todoAddTitle->setText("");
            _todoAddText->setPlainText("");
            _todoAddDate->setDate(QDate::currentDate());
        });
    }
}

void MainWindow::updateForm(){
    // Reset Button
    _todoAddButton->setText("Add");
    _todoAddButton->setStyleSheet("background-color: white; color: black");
}


