#ifndef STUINFOR_MANAGE_H
#define STUINFOR_MANAGE_H

#include <QWidget>
namespace Ui {
class stuinfor_manage;
}

class stuinfor_manage : public QWidget
{
    Q_OBJECT
public:
    explicit stuinfor_manage(QWidget *parent = nullptr);
    ~stuinfor_manage();
private slots:

    void on_search_Button_clicked();

    void on_add_Button_clicked();

    void on_deleteButton_clicked();

    void on_updateButton_clicked();

    void on_backButton_clicked();

    void on_seeallButton_clicked();

private:
    Ui::stuinfor_manage *ui;
};

#endif // STUINFOR_MANAGE_H
