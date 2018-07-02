#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 900, 600))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        Bullet *b = new Bullet(QString("click"));
        b->setPos(player->x() + player->pixmap().width()/3, player->y() - player->pixmap().height()/2);
        scene->addItem(b);
    }
    else if (e->button() == Qt::RightButton)
    {
        player->spAttack();
    }

}

void MainWindow::game()
{

    timer = new QTimer();
    ctimer = new QTimer();

    enemy = new Enemy();
    scene->addItem(enemy);
    enemy->setPos(0,25);
    player = new Player();
    scene->addItem(player);
    player->setPos(400,500);

    score = new Score();
    scene->addItem(score);
    score->setPos(0, 580);

    second = 0;
    minute = 0;
    ui->label_time->setText(QString("Time = 0 : 0"));
    connect(ctimer, SIGNAL(timeout()), this, SLOT(countTime()));

    player->connect(timer, SIGNAL(timeout()), player, SLOT(move()));
}


void MainWindow::minusPlayer()
{
    player->hurt();
}

void MainWindow::minusEnemy()
{
    enemy->hurt();
    score->increase();
}

void MainWindow::win()
{
    timer->stop();
    ctimer->stop();
    player->t->stop();

    score->kill();

    QMessageBox msg(QMessageBox::NoIcon, "End", "You win!");
    msg.setIconPixmap(QPixmap(":/win.png"));

    if (msg.exec() == QMessageBox::Ok)
    {
        this->hide();
        emit playagain();
    }
}

void MainWindow::lose()
{
    timer->stop();
    ctimer->stop();
    enemy->t->stop();
    enemy->bt->stop();

    QMessageBox msg(QMessageBox::NoIcon, "End", "You lose!");
    msg.setIconPixmap(QPixmap(":/lose.png"));

    if (msg.exec() == QMessageBox::Ok)
    {
        this->hide();
        emit playagain();
    }

}

void MainWindow::countTime()
{
    second++;

    if (second >= 60)
    {
        minute++;
        second = 0;
    }

    QString s = QString("Time = ") + QString::number(minute) + QString(" : ") + QString::number(second);
    ui->label_time->setText(s);


}

void MainWindow::gameStart()
{
    this->setWindowState(Qt::WindowMaximized);
    this->show();

    scene->clear();
    game();

    timer->start(10);
    ctimer->start(1000);
    enemy->t->start(10);
    enemy->bt->start(500);
    player->t->start(500);
}


void MainWindow::conti()
{
    this->setWindowState(Qt::WindowMaximized);
    this->show();

    timer->start(10);
    ctimer->start(1000);
    enemy->t->start(10);
    enemy->bt->start(500);
    player->t->start(500);
}


void MainWindow::on_pauseButton_clicked()
{
    this->hide();
    emit dialogShow();
    timer->stop();
    ctimer->stop();
    enemy->t->stop();
    enemy->bt->stop();
    player->t->stop();
}

void MainWindow::on_endButton_clicked()
{
    emit quit();
}
