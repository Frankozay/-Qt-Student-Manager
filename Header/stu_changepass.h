#ifndef STU_CHANGEPASS_H
#define STU_CHANGEPASS_H

#include <QWidget>
namespace Ui {
class stu_changepass;
}

class stu_changepass : public QWidget
{
    Q_OBJECT
public:
    explicit stu_changepass(QWidget *parent = nullptr);
    ~stu_changepass();
private slots:
    void on_updateButton_clicked();

    void on_backButton_clicked();

private:
    Ui::stu_changepass *ui;
};

#endif // STU_CHANGEPASS_H
