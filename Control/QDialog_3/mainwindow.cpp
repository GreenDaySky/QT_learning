#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建菜单项 弹出对话框
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        //qDebug() << "哈哈";

        //对话框 模态对话框（不可以对其他窗口操作） 非模态对话框（可以）
       // QDialog dig(this);创建在栈上 一闪而过


        //模态方式启动 阻塞
//        dig.exec();
        //非模态方式启动

        //堆上创建
//        QDialog * dig = new QDialog(this);
//        dig->resize(200, 100);
//        dig->show();

//        //需要设置属性防止内存泄漏
//        dig->setAttribute(Qt::WA_DeleteOnClose);


        //使用标准化对话框  QMessageBox
        //错误对话框 模态
        //QMessageBox::critical(this, "错误", "critial");

        //问题对话框
        //参数1：父类 参数2：标题 参数3：提示 参数4：案件类型 参数5：关联回车的按键
//        if(QMessageBox::Save == QMessageBox::question(this, "问题", "question", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
//        {
//            qDebug() << "保存";
//        }
//        else{
//            qDebug() << "取消";
//        }

        //警告对话框
        //QMessageBox::warning(this, "警告", "warning");

        //选择颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << color.red() << color.green() << color.blue();

        //文件对话框
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\94819\\Desktop", "(*.txt *.png");
        qDebug() << path;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
