#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //单项按钮默认选中
    ui->rBtnMan->setChecked(true);

    //点击女 打印一段话
    connect(ui->rBtnWoman, &QRadioButton::clicked,[=](){
       qDebug() << "女";
    });

    //多选框选中后打印内容
    //选中是2 未选中是0 半选中是1

    connect(ui->checkBox, &QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    //利用listWidget写诗
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");

//    //设置对齐方式
//    item->setTextAlignment(Qt::AlignHCenter);

//    ui->listWidget->addItem(item);

    //QStringList  ==  QList<String>
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";

    //匿名对象 可以直接替换list
    //QStringList() << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}
