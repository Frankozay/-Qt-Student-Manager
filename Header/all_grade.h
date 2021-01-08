#ifndef ALL_GRADE_H
#define ALL_GRADE_H

#include <QWidget>
namespace Ui {
class all_grade;
}

class all_grade : public QWidget
{
    Q_OBJECT
public:
    explicit all_grade(QWidget *parent = nullptr);
    ~all_grade();

private slots:

    void on_backButton_clicked();

private:
    Ui::all_grade *ui;
};

#endif // ALL_GRADE_H
