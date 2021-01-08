#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTextCodec>
#include <manager.h>
#include <student.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_LoginButton_clicked();

    void on_userButton_clicked();

    void on_adminButton_clicked();

    void on_RemitButton_clicked();

private:
    Ui::MainWindow *ui;
    manager *m;
    student *s;
};

#endif // MAINWINDOW_H
