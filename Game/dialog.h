#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void receiveShow();
    void playAgainShow();
    void on_bossButton_clicked();
    void on_contiButton_clicked();
    void on_endButton_clicked();


signals:
    void mainwindowShow();
    void contiShow();
    void quit();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
