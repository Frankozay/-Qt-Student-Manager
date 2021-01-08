#ifndef USER_CHANGEPASSWORD_H
#define USER_CHANGEPASSWORD_H

#include <QWidget>

namespace Ui {
class user_changepassword;
}

class user_changepassword : public QWidget
{
    Q_OBJECT
public:
    explicit user_changepassword(QWidget *parent = nullptr);
    ~user_changepassword();
private slots:

    void on_changePushButton_clicked();

    void on_backPushButton_clicked();

private:
    Ui::user_changepassword *ui;
};

#endif // USER_CHANGEPASSWORD_H
