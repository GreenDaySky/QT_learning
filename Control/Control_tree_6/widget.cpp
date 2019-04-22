#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TreeWidget控件使用
    //添加头

    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄姓名");

    //添加项目
    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem * minItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList() << "智力");
    //添加顶层项目
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);


    QStringList heroL1;
    heroL1 << "孙悟空" << "前排战士";

    QStringList heroL2;
    heroL2 << "蜘蛛精" << "后排巫师";

    QStringList heroL3;
    heroL3 << "猪八戒" << "前排坦克";


    //追加子项目 子项目也是QTreeWidgetItem
    QTreeWidgetItem * lil = new QTreeWidgetItem(heroL1);
    liItem->addChild(lil);
    QTreeWidgetItem * minl = new QTreeWidgetItem(heroL2);
    minItem->addChild(minl);
    QTreeWidgetItem * zhil = new QTreeWidgetItem(heroL3);
    zhiItem->addChild(zhil);

}

Widget::~Widget()
{
    delete ui;
}
