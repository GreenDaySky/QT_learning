#include "widget.h"
#include <QPushButton>

//Teacher类  Student类
//下课后 老师；饿了 学生：吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    zt = new Teacher(this);
    st = new Student(this);

    void(Teacher:: *teaherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
//    void(Teacher:: *tSignal)(void) = &Teacher::hungry;
//    void(Student:: *sSlot)(void) = &Student::treat;
//    //如何触发重载

//    connect(zt, tSignal, st, sSlot);
    connect(zt, teaherSignal, st, studentSlot);


//    classIsOver();
    //点击按钮 下课
    QPushButton * btn = new QPushButton("下课", this);

    void(Teacher:: *noTeacherSignal)(void) = &Teacher::hungry;
    void(Student:: *nostudentSlot)(void) = &Student::treat;
    //触发无参
    connect(btn, &QPushButton::clicked, zt, noTeacherSignal);
    connect(zt, noTeacherSignal, st, nostudentSlot);

    resize(600, 400);

    QPushButton * btn2 = new QPushButton("aaa", this);
    btn2->move(100, 100);

    connect(btn2, &QPushButton::clicked, this, [=](){
        zt->hungry("辣子鸡丁");
    });
}

void Widget::classIsOver()
{
    emit zt->hungry();//触发无参
    emit zt->hungry("牛肉");
}

Widget::~Widget()
{
}
