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
QString priority;

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

    connect(ui->LowPriority, &QRadioButton::clicked, this, &MainWindow::onRadioButtonClicked);
    connect(ui->mediumPriority, &QRadioButton::clicked, this, &MainWindow::onRadioButtonClicked);
    priority = ui->mediumPriority->text();
    connect(ui->highPriority, &QRadioButton::clicked, this, &MainWindow::onRadioButtonClicked);

    _todoAddDate = ui->todoAddDate;
    connect(_todoAddDate, &QDateEdit::dateChanged, this, &MainWindow::updateForm);
    _todoAddDate->setDate(QDate::currentDate());

    connect(ui->SortButton, &QPushButton::clicked, this, &MainWindow::sortTodo);

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
        itemWidget->setPriority(priority);

        QListWidgetItem* newItem = new QListWidgetItem();
        newItem->setSizeHint(itemWidget->sizeHint());
        if (priority == "High") {
            newItem->setBackground(QColor(255, 0, 0));
        }
        else if (priority == "Medium") {
            newItem->setBackground(QColor(255, 127, 0));
        }
        else {
            newItem->setBackground(QColor(0, 255, 0));
        }

        _todoList->addItem(newItem);
        _todoList->setItemWidget(newItem, itemWidget);

        // Clear Form
        QTimer::singleShot(2000, [](){
            _todoAddTitle->setText("");
            _todoAddText->setPlainText("");
            _todoAddDate->setDate(QDate::currentDate());
        });
    }
}

void MainWindow::onRadioButtonClicked(bool checked)
{
    QRadioButton* radioButton = qobject_cast<QRadioButton*>(sender());
    if (radioButton && checked) {
        priority = radioButton->text();
    }
}


void MainWindow::updateForm(){
    // Reset Button
    _todoAddButton->setText("Add");
    _todoAddButton->setStyleSheet("background-color: white; color: black");
}

void MainWindow::sortTodo() {
    static bool sorted = false;
    if (!sorted) {
        // trier la liste en ordre croissant de date
        _todoList->sortItems(Qt::AscendingOrder);
        sorted = true;
    }
    else {
        // trier dans l'ordre décroissant de dates
        _todoList->sortItems(Qt::DescendingOrder);
        sorted = false;
    }
}

