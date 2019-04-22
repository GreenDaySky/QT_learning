#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //通过UI寻找空间
    //ui->actionnew->setIcon(QIcon("C:/Users/94819/Pictures/Camera Roll/apple.jpg"));
    //添加资源文件到项目中

    //使用资源文件 ": + 前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/fruit/cindy.png"));
    ui->actionopen->setIcon(QIcon(":/fruit/apple.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
