#ifndef STU_INFORQUERY_H
#define STU_INFORQUERY_H

#include <QWidget>

namespace Ui {
class stu_inforquery;
}
class stu_inforquery : public QWidget
{
    Q_OBJECT
public:
    explicit stu_inforquery(QWidget *parent = nullptr);
    ~stu_inforquery();
private slots:
    void on_sno_pushButton_clicked();

    void on_sname_pushButton_clicked();

    void on_backButton_clicked();

private:
    Ui::stu_inforquery *ui;
};

#endif // STU_INFORQUERY_H
