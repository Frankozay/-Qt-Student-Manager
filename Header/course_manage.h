#ifndef COURSE_MANAGE_H
#define COURSE_MANAGE_H

#include <QWidget>

namespace Ui {
class course_manage;
}


class course_manage : public QWidget
{
    Q_OBJECT
public:
    explicit course_manage(QWidget *parent = nullptr);
    ~course_manage();
private slots:

    void on_searchpushButton_clicked();

    void on_addPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_updatePushButton_clicked();

    void on_backPushButton_clicked();

    void on_allCoursePushButton_clicked();

private:
    Ui::course_manage *ui;
};

#endif // COURSE_MANAGE_H
