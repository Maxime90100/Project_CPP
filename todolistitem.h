#ifndef TODOLISTITEM_H
#define TODOLISTITEM_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>

class TodoListItem : public QWidget
{
    Q_OBJECT
public:
    explicit TodoListItem(QWidget *parent = nullptr);
    void setTitle(const QString &title);
    void setText(const QString &text);
    void setPriority(const QString &priority);
    void setDate(const QDate &date);
    void edit();

private:
    QLabel *m_titleLabel;
    QTextEdit *m_textEdit;
    QString m_priority;
    QDateEdit *m_dateEdit;
    QPushButton *m_pushButton;
    QVBoxLayout *m_layout;
    bool editable;
};

#endif
