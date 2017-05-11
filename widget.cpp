#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h> // random number

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    showFullScreen();

    // instantiate sheep

    // sheeps[0] == sheepLeft
    Sheep *tempSheep = new Sheep(this,1,1);
    tempSheep->move(100,610);
    tempSheep->setPixmap(QPixmap("://resources/sheepright.png").scaled(200,170));
    sheeps.append(tempSheep);
    tempSheep->show();

    // sheeps[1] == sheepRight
    tempSheep = new Sheep(this,-1,-1);
    tempSheep->move(1600,610);
    tempSheep->setPixmap(QPixmap("://resources/sheep.png").scaled(200,170));
    sheeps.append(tempSheep);
    tempSheep->show();

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    timer->setInterval(10);
    timer->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_Escape)
        close();
}

void Widget::onTimerHit()
{
    sheeps.at(0)->moveSheep();
    sheeps.at(1)->moveSheep();

    if (sheeps.at(0)->x() + sheeps.at(0)->width() >= sheeps.at(1)->x()) {
        int whichSheep = rand() % 2; // random number between 0 and 99.

        if (whichSheep == 1) {
            sheeps.at(1)->setSpeed(10);
        } else if (whichSheep == 0) {
            sheeps.at(0)->setSpeed(-10);
        }
    }
}

Sheep::Sheep(QWidget *parent, int _speed, int _walkSpeed): QLabel(parent), speed(_speed), walkSpeed(_walkSpeed)
{
}

void Sheep::moveSheep()
{
    move(x() + speed, y());

    if (speed > walkSpeed)
        speed --;
    else if (speed < walkSpeed)
        speed ++;
}

void Sheep::setSpeed(int speed)
{
    this->speed = speed;
}
