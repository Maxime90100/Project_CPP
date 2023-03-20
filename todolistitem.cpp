#include "todolistitem.h"

TodoListItem::TodoListItem(QWidget *parent) : QWidget(parent)
{   
    TodoListItem::editable = false;

    m_layout = new QVBoxLayout(this);

    m_titleLabel = new QLabel(this);
    m_titleLabel->setDisabled(true);
    m_layout->addWidget(m_titleLabel);

    m_textEdit = new QTextEdit(this);
    m_textEdit->setDisabled(true);
    m_layout->addWidget(m_textEdit);

    m_dateEdit = new QDateEdit(this);
    m_dateEdit->setDisabled(true);
    m_layout->addWidget(m_dateEdit);

    m_pushButton = new QPushButton(this);
    m_pushButton->setText("Edit");
    connect(m_pushButton, &QPushButton::clicked, this, &TodoListItem::edit);
    m_layout->addWidget(m_pushButton);

    setLayout(m_layout);
}

void TodoListItem::setTitle(const QString &title)
{
    m_titleLabel->setText(title);
}

void TodoListItem::setText(const QString &text)
{
    m_textEdit->setPlainText(text);
}

void TodoListItem::setDate(const QDate &date)
{
    m_dateEdit->setDate(date);
}

void TodoListItem::edit()
{
    if(editable){
        m_pushButton->setText("Save");
        m_pushButton->setStyleSheet("background-color: green; color: white");
    }else{
        m_pushButton->setText("Edit");
        m_pushButton->setStyleSheet("background-color: white; color: black");
    }
    m_titleLabel->setDisabled(!editable);
    m_textEdit->setDisabled(!editable);
    m_dateEdit->setDisabled(!editable);
    editable = !editable;
}