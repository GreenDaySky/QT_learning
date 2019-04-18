#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请客";
}

void Student::treat(QString foodName)
{
    //qDebug() << "请客吃" << foodName;
    //QString ——> char*
    qDebug() << "请客吃" << foodName.toUtf8().data();
}
