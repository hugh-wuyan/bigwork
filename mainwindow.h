#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_pushButton_2_clicked();

    void on_pu_clicked();

private:
    Ui::MainWindow *ui;
//商业和公积金贷款
    //单位，面积
    int unitprice;//单价
    int area;//面积
    double proportion;//按揭成数
    int year;//按揭年数
    double lili;//利率
    //贷款总额
    double money;//贷款总额
    //组合型
    double money1;
    double money2;
    double lili1;
    double lili2;
};

#endif // MAINWINDOW_H
