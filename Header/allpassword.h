#ifndef ALLPASSWORD_H
#define ALLPASSWORD_H

#include <QWidget>
namespace Ui {
class allpassword;
}

class allpassword : public QWidget
{
    Q_OBJECT
public:
    explicit allpassword(QWidget *parent = nullptr);
    ~allpassword();
private slots:

    void on_backButton_clicked();

private:
    Ui::allpassword *ui;
};

#endif // ALLPASSWORD_H
