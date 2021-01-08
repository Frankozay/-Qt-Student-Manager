#ifndef ALLSTUINFOR_H
#define ALLSTUINFOR_H

#include <QWidget>
namespace Ui {
class allstuinfor;
}

class allstuinfor : public QWidget
{
    Q_OBJECT
public:
    explicit allstuinfor(QWidget *parent = nullptr);
    ~allstuinfor();

private slots:

    void on_backButton_clicked();

private:
    Ui::allstuinfor *ui;
};

#endif // ALLSTUINFOR_H
