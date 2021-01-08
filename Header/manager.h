#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>

namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT
public:
    explicit manager(QWidget *parent = 0);
    ~manager();

private slots:

    void on_backButton_clicked();

    void on_user_manageButton_clicked();

    void on_stu_manageButton_clicked();

    void on_course_manageButton_clicked();

    void on_score_manageButton_clicked();

private:
    Ui::manager *ui;
};

#endif // MANAGER_H
