#ifndef USER_STUPASS_H
#define USER_STUPASS_H

#include <QWidget>

namespace Ui {
class user_stupass;
}
class user_stupass : public QWidget
{
    Q_OBJECT
public:
    explicit user_stupass(QWidget *parent = nullptr);
    ~user_stupass();
private slots:

    void on_searchButton_clicked();

    void on_updateButton_clicked();

    void on_backButton_clicked();

    void on_allpasswordButton_clicked();

private:
    Ui::user_stupass *ui;
};

#endif // USER_STUPASS_H
