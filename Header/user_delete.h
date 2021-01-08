#ifndef USER_DELETE_H
#define USER_DELETE_H

#include <QWidget>

namespace Ui{
class user_delete;
}

class user_delete : public QWidget
{
    Q_OBJECT
public:
    explicit user_delete(QWidget *parent = nullptr);
    ~user_delete();
private slots:

    void on_backPushButton_clicked();

    void on_deletePushButton_clicked();

private:
    Ui::user_delete *ui;
};

#endif // USER_DELETE_H
