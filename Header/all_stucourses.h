#ifndef ALL_GRADE_H
#define ALL_GRADE_H

#include <QWidget>
namespace Ui {
class all_stucourses;
}

class all_stucourses : public QWidget
{
    Q_OBJECT
public:
    explicit all_stucourses(QWidget *parent = nullptr);
    ~all_stucourses();

private slots:

    void on_backButton_clicked();

private:
    Ui::all_stucourses *ui;
};

#endif // ALL_GRADE_H
