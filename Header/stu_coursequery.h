#ifndef STU_COURSEQUERY_H
#define STU_COURSEQUERY_H

#include <QWidget>

namespace Ui {
class stu_coursequery;
}
class stu_coursequery : public QWidget
{
    Q_OBJECT
public:
    explicit stu_coursequery(QWidget *parent = nullptr);
    ~stu_coursequery();

private slots:

    void on_backButton_clicked();

    void on_snameButton_clicked();

    void on_snoButton_clicked();

private:
    Ui::stu_coursequery *ui;
};

#endif // STU_COURSEQUERY_H
