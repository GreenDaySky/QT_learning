#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    //this->setMouseTracking(true);
}

//鼠标进入
void MyLabel::enterEvent(QEvent *)
{
    qDebug() << "鼠标进入了";
}

//鼠标离开

void MyLabel::leaveEvent(QEvent *)
{
    qDebug() << "鼠标离开了";
}


//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev)
{

//    if(ev->button() == Qt::LeftButton)
    {
    //找摁下的位置
    QString Str = QString("鼠标摁下了！！！x = %1 y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << Str;
    }
}

//鼠标释放
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug() << "鼠标释放了";
}

//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //持续状态 需要用button 用与操作符进行判断
    //if(ev->buttons() & Qt::LeftButton)
    {
        QString Str = QString("鼠标移动了！！！x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << Str;
    }

}

//事件分发 Event事件

bool MyLabel::event(QEvent *e)
{
    //通常不会做拦截
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * ev = static_cast<QMouseEvent *>(e);

        QString Str = QString("鼠标按下了！！！x = %1 y = %2").arg(ev->x()).arg(ev->y());

        qDebug() << Str;

        return true;
    }
    //其他事件让父类做默认处理
    return QLabel::event(e);
}
