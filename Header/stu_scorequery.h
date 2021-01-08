#ifndef STU_SCOREQUERY_H
#define STU_SCOREQUERY_H

#include <QWidget>

namespace Ui {
class stu_scorequery;
}

class stu_scorequery : public QWidget
{
    Q_OBJECT
public:
    explicit stu_scorequery(QWidget *parent = nullptr);
    ~stu_scorequery();

private slots:
    void on_snoButton_clicked();

    void on_snameButton_clicked();

    void on_backButton_clicked();

private:
    Ui::stu_scorequery *ui;
};

#endif // STU_SCOREQUERY_H
