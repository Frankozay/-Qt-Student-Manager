#ifndef ALLSC_H
#define ALLSC_H

#include <QWidget>
namespace Ui {
class allsc;
}
class allsc : public QWidget
{
    Q_OBJECT
public:
    explicit allsc(QWidget *parent = nullptr);
    ~allsc();
private slots:

    void on_backButton_clicked();

private:
    Ui::allsc *ui;
};

#endif // ALLSC_H
