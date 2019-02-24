#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QObject>

class Paddle:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Paddle(QGraphicsItem *parent=NULL);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent* event);
    void move_paddle(double x);
    qreal height();
    qreal width();
    double getCenterX();
    double rightCornerX();
    double leftCornerX();

    void timerEvent(QTimerEvent *);
    void CollisionChecker();//(qreal x,qreal y, double radius);
signals:
    void stop_game();
    void ballCollision(double position,bool corners);
private:
    bool foo = true;
    double paddle_height;
    double paddle_width;
    QMap<int,bool> keys;
};

#endif // PADDLE_H
