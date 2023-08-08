#include "content.h"

#include <QApplication>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>


int main(int argc, char *argv[])
{
    /*修改用户资料功能*/
    QApplication a(argc, argv);
    QFont font("AR PL KaitiM GB", 12);  //字体和字号
    a.setFont(font);

    //新建水平分割窗口,作为主布局框
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setOpaqueResize(true);
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0, QObject::tr("基本信息"));
    list->insertItem(1, QObject::tr("联系方式"));
    list->insertItem(2, QObject::tr("详细资料"));
    Content *content = new Content(splitterMain);
    QObject::connect(list, SIGNAL(currentRowChanged(int)), content->stack, SLOT(setCurrentIndex(int)));//

    //设计主布局框标题
    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    //设计主布局框最小尺寸
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    //设计主布局框最大尺寸
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();

//    Content w;
//    w.show();
    return a.exec();
}
