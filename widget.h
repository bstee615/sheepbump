#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QPixmap>

class Sheep : public QLabel
{
    Q_OBJECT

public:
    Sheep(QWidget *parent, int _speed, int _walkSpeed);

    void moveSheep();

    void setSpeed(int speed);

private:
    int speed;
    int walkSpeed;
};

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void keyPressEvent(QKeyEvent *ev);

private:
    Ui::Widget *ui;
    QList<Sheep*> sheeps;

    QTimer *timer;

private slots:
    void onTimerHit();
};

#endif // WIDGET_H
