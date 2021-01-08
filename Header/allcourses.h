#ifndef ALLCOURSES_H
#define ALLCOURSES_H

#include <QWidget>

namespace Ui {
class allcourses;
}
class allcourses : public QWidget
{
    Q_OBJECT
public:
    explicit allcourses(QWidget *parent = nullptr);
    ~allcourses();

private slots:

    void on_backButton_clicked();

private:
    Ui::allcourses *ui;
};

#endif // ALLCOURSES_H
