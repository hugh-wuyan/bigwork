#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<qmessagebox.h>
#include<QString>
#include<QPushButton>
#include "QStringList"
#include<QButtonGroup>
#include<cmath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1000,750);
    QStringList list1,list2;
    list1<<"2"<<"2.5"<<"3"<<"3.5"<<"4"<<"4.5"<<"5"<<"5.5"<<"6"<<"6.5"<<"7"<<"7.5"<<"8";
    ui->comboBox1->addItems(list1);
    ui->comboBox5->addItems(list1);
    list2<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20"<<"21"<<"22"<<"23"<<"24"<<"25";
    ui->comboBox2->addItems(list2);
    ui->comboBox6->addItems(list2);
    ui->comboBox8->addItems(list2);
    ui->comboBox3->addItem("等额本息");
    ui->comboBox3->addItem("等额本金");
    ui->comboBox7->addItem("等额本息");
    ui->comboBox7->addItem("等额本金");
    ui->comboBox9->addItem("等额本息");
    ui->comboBox9->addItem("等额本金");
    ui->lineEdit1->setValidator(new QIntValidator(1,100000));
    ui->lineEdit2->setValidator(new QIntValidator(1,1000));
    ui->lineEdit3->setValidator(new QDoubleValidator(1.0,99.0,2));
    ui->lineEdit4->setValidator(new QIntValidator(1,100000000));
    ui->lineEdit5->setValidator(new QIntValidator(1,100000));
    ui->lineEdit6->setValidator(new QIntValidator(1,1000));
    ui->lineEdit7->setValidator(new QIntValidator(1,100000000));
    ui->lineEdit8->setValidator(new QDoubleValidator(1.0,99.0,2));
    ui->lineEdit9->setValidator(new QIntValidator(1,100000000));
    ui->lineEdit10->setValidator(new QDoubleValidator(1.0,99.0,2));
    ui->lineEdit11->setValidator(new QIntValidator(1,100000000));
    ui->lineEdit12->setValidator(new QDoubleValidator(1.0,99.0,2));
    ui->textBrowser->append("请在左边输入数字和小数点，单价请小于十万，面积请小于1000，贷款金额小于1亿，利率两位小数");
    QPixmap pixmap = QPixmap(":/1");
        QPalette  palette (this->palette());
        palette .setBrush(QPalette::Background, QBrush(pixmap));
        this-> setPalette( palette );
        setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    double firstpay;
    double monthgive;
    double totallend;
    double lixi;
    double totalback;
    int month;
    double du;
    double k;
    int i;
    ui->textBrowser->clear();
    if(ui->tabWidget->currentIndex()==0)//商业
    {
        if(ui->tabWidget_3->currentIndex()==0)//单位面积
        {
            unitprice=ui->lineEdit1->text().toDouble();
            area=ui->lineEdit2->text().toDouble();
            proportion=ui->comboBox1->currentIndex()+4;
            proportion=proportion/2;
            year=ui->comboBox2->currentIndex()+1;
            lili=ui->lineEdit3->text().toDouble();
            if(unitprice==0||area==0||lili==0)
            {
                ui->textBrowser->clear();
                ui->textBrowser->append("错误，请输入数据。");
            }
            else
            {
                if(ui->comboBox3->currentIndex()==0)//等额本息
                {
                    totallend=area*unitprice*proportion/10;
                    firstpay=area*unitprice-totallend;
                    month=year*12;
                    lili=lili/12/100;
                    du=totallend*lili;
                    k=lili+1;
                    for(i=0;i<month-1;i++)
                    {k=k*(1+lili);}
                    monthgive=du*k/(k-1);
                    totalback=monthgive*month;
                    lixi=totalback-totallend;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("首付："+QString::number(firstpay,'f',2)+"元");
                    ui->textBrowser->append("每月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(totallend,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                }
                else//等额本金
                {
                    totallend=area*unitprice*proportion/10;
                    firstpay=area*unitprice-totallend;
                    month=year*12;
                    lili=lili/12/100;
                    monthgive=totallend/month+totallend*lili;
                    du=totallend/month*lili;
                    totalback=monthgive*month-du*(month-1)*month/2;
                    lixi=totalback-totallend;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("首付："+QString::number(firstpay,'f',2)+"元");
                    ui->textBrowser->append("首月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("每月递减："+QString::number(du,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(totallend,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                }
            }

        }
        else//贷款总额计算
        {
            money=ui->lineEdit4->text().toDouble();
            year=ui->comboBox2->currentIndex()+1;
            lili=ui->lineEdit3->text().toDouble();
            if(money==0||lili==0)
            {
                ui->textBrowser->clear();
                ui->textBrowser->append("错误，请输入数据。");
            }
            else
            {
                if(ui->comboBox3->currentIndex()==0)//等额本息
                    {
                    month=year*12;
                    lili=lili/12/100;
                    du=money*lili;
                    k=lili+1;
                    for(i=0;i<month-1;i++)
                    {k=k*(1+lili);}
                    monthgive=du*k/(k-1);
                    totalback=monthgive*month;
                    lixi=totalback-money;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("每月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(money,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                    }
                else//等额本金
                    {
                    month=year*12;
                    lili=lili/12/100;
                    monthgive=money/month+money*lili;
                    du=money/month*lili;
                    totalback=monthgive*month-du*(month-1)*month/2;
                    lixi=totalback-money;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("首月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("每月递减："+QString::number(du,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(money,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                    }
            }
            }

    }
    if(ui->tabWidget->currentIndex()==1)//公积金
    {
        if(ui->tabWidget_4->currentIndex()==0)//单位面积
        {
            unitprice=ui->lineEdit5->text().toDouble();
            area=ui->lineEdit6->text().toDouble();
            proportion=ui->comboBox5->currentIndex()+4;
            proportion=proportion/2;
            year=ui->comboBox6->currentIndex()+1;
            lili=ui->lineEdit8->text().toDouble();
            if(unitprice==0||area==0||lili==0)
            {
                ui->textBrowser->clear();
                ui->textBrowser->append("错误，请输入数据。");
            }
            else
            {
                if(ui->comboBox7->currentIndex()==0)//等额本息
                {
                    totallend=area*unitprice*proportion/10;
                    firstpay=area*unitprice-totallend;
                    month=year*12;
                    lili=lili/12/100;
                    du=totallend*lili;
                    k=lili+1;
                    for(i=0;i<month-1;i++)
                    {k=k*(1+lili);}
                    monthgive=du*k/(k-1);
                    totalback=monthgive*month;
                    lixi=totalback-totallend;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("首付："+QString::number(firstpay,'f',2)+"元");
                    ui->textBrowser->append("每月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(totallend,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                }
                else//等额本金
                {
                    totallend=area*unitprice*proportion/10;
                    firstpay=area*unitprice-totallend;
                    month=year*12;
                    lili=lili/12/100;
                    monthgive=totallend/month+totallend*lili;
                    du=totallend/month*lili;
                    totalback=monthgive*month-du*(month-1)*month/2;
                    lixi=totalback-totallend;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("首付："+QString::number(firstpay,'f',2)+"元");
                    ui->textBrowser->append("首月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("每月递减："+QString::number(du,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(totallend,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                }
            }

        }
        else//贷款总额计算
        {
            money=ui->lineEdit7->text().toDouble();
            year=ui->comboBox6->currentIndex()+1;
            lili=ui->lineEdit8->text().toDouble();
            if(money==0||lili==0)
            {
                ui->textBrowser->clear();
                ui->textBrowser->append("错误，请输入数据。");
            }
            else
            {
                if(ui->comboBox7->currentIndex()==0)//等额本息
                    {
                    month=year*12;
                    lili=lili/12/100;
                    du=money*lili;
                    k=lili+1;
                    for(i=0;i<month-1;i++)
                    {k=k*(1+lili);}
                    monthgive=du*k/(k-1);
                    totalback=monthgive*month;
                    lixi=totalback-money;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("每月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(money,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                    }
                else//等额本金
                    {
                    month=year*12;
                    lili=lili/12/100;
                    monthgive=money/month+money*lili;
                    du=money/month*lili;
                    totalback=monthgive*month-du*(month-1)*month/2;
                    lixi=totalback-money;
                    ui->textBrowser->clear();
                    ui->textBrowser->append("计算结果：");
                    ui->textBrowser->append("首月月供："+QString::number(monthgive,'f',2)+"元");
                    ui->textBrowser->append("每月递减："+QString::number(du,'f',2)+"元");
                    ui->textBrowser->append("贷款总额："+QString::number(money,'f',2)+"元");
                    ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                    ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                    ui->textBrowser->append("月数："+QString::number(month)+"个月");
                    }
            }

        }
    }
    if(ui->tabWidget->currentIndex()==2)//组合型
    {
        money1=ui->lineEdit9->text().toDouble();
        lili1=ui->lineEdit10->text().toDouble();
        money2=ui->lineEdit11->text().toDouble();
        lili2=ui->lineEdit12->text().toDouble();
        year=ui->comboBox8->currentIndex()+1;
        if(money1==0||money2==0||lili1==0||lili2==0)
        {
            ui->textBrowser->clear();
            ui->textBrowser->append("错误，请输入数据。");
        }
        else
        {
            if(ui->comboBox9->currentIndex()==0)//等额本息
            {
                month=year*12;
                lili1=lili1/12/100;
                lili2=lili2/12/100;

                du=money1*lili1;
                k=lili1+1;
                for(i=0;i<month-1;i++)
                {k=k*(1+lili1);}
                monthgive=du*k/(k-1);

                du=money2*lili2;
                k=lili2+1;
                for(i=0;i<month-1;i++)
                {k=k*(1+lili2);}
                monthgive=monthgive+du*k/(k-1);
                totalback=monthgive*month;
                lixi=totalback-money1-money2;
                ui->textBrowser->clear();
                ui->textBrowser->append("计算结果：");
                ui->textBrowser->append("每月月供："+QString::number(monthgive,'f',2)+"元");
                ui->textBrowser->append("贷款总额："+QString::number(money1+money2,'f',2)+"元");
                ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                ui->textBrowser->append("月数："+QString::number(month)+"个月");

            }
            else//等额本金
            {
                month=year*12;
                lili1=lili1/12/100;
                lili2=lili2/12/100;
                lili=lili/12/100;
                monthgive=money1/month+money1*lili1+money2/month+money2*lili2;
                du=money1/month*lili1+money2/month*lili2;
                totalback=monthgive*month-du*(month-1)*month/2;
                lixi=totalback-money;
                ui->textBrowser->clear();
                ui->textBrowser->append("计算结果：");
                ui->textBrowser->append("首月月供："+QString::number(monthgive,'f',2)+"元");
                ui->textBrowser->append("每月递减："+QString::number(du,'f',2)+"元");
                ui->textBrowser->append("贷款总额："+QString::number(money1+money2,'f',2)+"元");
                ui->textBrowser->append("利息："+QString::number(lixi,'f',2)+"元");
                ui->textBrowser->append("还款总额："+QString::number(totalback,'f',2)+"元");
                ui->textBrowser->append("月数："+QString::number(month)+"个月");
            }
        }
    }

}

void MainWindow::on_pu_clicked()
{
    ui->textBrowser->clear();
    ui->lineEdit1->clear();
    ui->lineEdit2->clear();
    ui->lineEdit3->clear();
    ui->lineEdit4->clear();
    ui->lineEdit5->clear();
    ui->lineEdit6->clear();
    ui->lineEdit7->clear();
    ui->lineEdit8->clear();
    ui->lineEdit9->clear();
    ui->lineEdit10->clear();
    ui->lineEdit11->clear();
    ui->lineEdit12->clear();
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_3->setCurrentIndex(0);
    ui->tabWidget_4->setCurrentIndex(0);
    ui->textBrowser->append("已清空，请输入数字和小数点");

}
