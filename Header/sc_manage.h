#ifndef SC_MANAGE_H
#define SC_MANAGE_H

#include <QWidget>

namespace Ui {
class sc_manage;
}
class sc_manage : public QWidget
{
    Q_OBJECT
public:
    explicit sc_manage(QWidget *parent = nullptr);
    ~sc_manage();

private:
    void update_pointNavg(QString sno);

private slots:

    void on_searchButton_clicked();

    void on_addButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_backButton_clicked();

    void on_allgradeLineEdit_clicked();

private:
    Ui::sc_manage *ui;
};

#endif // SC_MANAGE_H
