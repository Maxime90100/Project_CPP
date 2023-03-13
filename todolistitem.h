#ifndef TODOLISTITEM_H
#define TODOLISTITEM_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QDateEdit>
#include <QVBoxLayout>

class TodoListItem : public QWidget
{
    Q_OBJECT
public:
    explicit TodoListItem(QWidget *parent = nullptr);
    void setTitle(const QString &title);
    void setText(const QString &text);
    void setDate(const QDate &date);

private:
    QLabel *m_titleLabel;
    QTextEdit *m_textEdit;
    QDateEdit *m_dateEdit;
    QVBoxLayout *m_layout;
};

#endif
