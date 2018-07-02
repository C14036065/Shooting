#include "dialog.h"
#include "ui_dialog.h"
#include <mainwindow.h>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowTitle(QString("Shooting Game"));
    QPixmap image(":/title.png");
    ui->label->setPixmap(image);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::receiveShow()
{
    this->show();
    ui->contiButton->setEnabled(true);
}

void Dialog::playAgainShow()
{
    this->show();
    ui->contiButton->setEnabled(false);
}

void Dialog::on_startButton_clicked()
{
    this->hide();
    ui->contiButton->setEnabled(false);
    emit mainwindowShow();
}

void Dialog::on_contiButton_clicked()
{
    this->hide();
    ui->contiButton->setEnabled(false);
    emit contiShow();
}

void Dialog::on_endButton_clicked()
{
    emit quit();
}
