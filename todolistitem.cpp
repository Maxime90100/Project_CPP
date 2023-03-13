#include "todolistitem.h"

TodoListItem::TodoListItem(QWidget *parent) : QWidget(parent)
{
    m_titleLabel = new QLabel(this);
    m_textEdit = new QTextEdit(this);
    m_dateEdit = new QDateEdit(this);
    m_layout = new QVBoxLayout(this);

    m_layout->addWidget(m_titleLabel);
    m_layout->addWidget(m_textEdit);
    m_layout->addWidget(m_dateEdit);

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
