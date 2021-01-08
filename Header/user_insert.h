#ifndef USER_INSERT_H
#define USER_INSERT_H

#include <QWidget>

namespace Ui{
class user_insert;
}

class user_insert : public QWidget
{
    Q_OBJECT
public:
    explicit user_insert(QWidget *parent = 0);
    ~user_insert();

private slots:

    void on_addPushButton_clicked();

    void on_backPushButton_clicked();

private:
    Ui::user_insert *ui;
};

#endif // USER_INSERT_H
