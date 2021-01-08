#ifndef USER_MANAGE_H
#define USER_MANAGE_H

#include <QWidget>

namespace Ui{
class user_manage;
}

class user_manage : public QWidget
{
    Q_OBJECT
public:
    explicit user_manage(QWidget *parent = 0);
    ~user_manage();

private slots:

    void on_createPushButton_clicked();

    void on_backPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_changePushButton_clicked();

    void on_stu_passwordButton_clicked();

private:
    Ui::user_manage *ui;
};

#endif // USER_MANAGE_H
