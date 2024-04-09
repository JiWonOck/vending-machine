#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);

    if (money >= 100){
        ui->pbCoffee->setEnabled(true);
        if (money >= 150){
            ui->pbTea->setEnabled(true);
            if (money >= 200){
                ui->pbMilk->setEnabled(true);
            } else {
                ui->pbMilk->setEnabled(false);
            }
        } else {
            ui->pbTea->setEnabled(false);
            ui->pbMilk->setEnabled(false);
        }
    } else {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    int coin500 = 0;
    int coin100 = 0;
    int coin50 = 0;
    int coin10 = 0;
    QString change;

    if(money >= 500){
        coin500 = money / 500;
        money %= 500;
    }
    if(money >= 100){
        coin100 = money / 100;
        money %= 100;
    }
    if(money >= 50){
        coin50 = money / 50;
        money %= 50;
    }
    if(money >= 10){
        coin10 = money / 10;
        money %= 10;
    }
    if(coin500 > 0) change = "500won : " + QString::number(coin500) + "\n";
    if(coin100 > 0) change += "100won : " + QString::number(coin100)+"\n";
    if(coin50 > 0) change += "50won : "  + QString::number(coin50)+"\n";
    if(coin10 > 0) change += "10won : " + QString::number(coin10);
    mb.setText(change);
    mb.information(this, "Reset",change);


}

