#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
namespace Ui {
class student;
}


class student : public QWidget
{
    Q_OBJECT
public:
    explicit student(QWidget *parent = nullptr);
    ~student();
private slots:

    void on_backButton_clicked();

    void on_passwordButton_clicked();

    void on_stu_queryButton_clicked();

    void on_score_queryButton_clicked();

    void on_course_queryButton_clicked();

private:
    Ui::student *ui;
};

#endif // STUDENT_H
