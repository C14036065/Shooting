#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

MainWindow *w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MainWindow;
    Dialog dlg;
    dlg.show();

    QObject::connect(&dlg, SIGNAL(mainwindowShow()), w, SLOT(gameStart()));
    QObject::connect(&dlg, SIGNAL(contiShow()), w, SLOT(conti()));
    QObject::connect(w, SIGNAL(dialogShow()), &dlg, SLOT(receiveShow()));
    QObject::connect(w, SIGNAL(playagain()), &dlg, SLOT(playAgainShow()));
    QObject::connect(w, SIGNAL(quit()), &a, SLOT(quit()));
    QObject::connect(&dlg, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
