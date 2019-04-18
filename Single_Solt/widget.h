#ifndef WIDGET_H
#define WIDGET_H
#include "teacher.h"
#include "student.h"
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void classIsOver();

    Teacher * zt;
    Student * st;
};

#endif // WIDGET_H
