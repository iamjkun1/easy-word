#include "content.h"

Content::Content(QWidget *parent)
    : QFrame(parent)
{

    stack = new QStackedWidget(this); //创建对象

    //堆栈窗口显示风格进行设计
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    //插入三个页面
    baseInfo = new BaseInfo();
//    contact = new Contact();
    contact = new Contact();
    detail = new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);
    //创建两个按钮
    AmendBtn = new QPushButton(tr("修改"));
    CloseBtn = new QPushButton(tr("关闭"));

//    connect(CloseBtn, &QPushButton::clicked, this, &Content::closeBtn_clicked());
    connect(AmendBtn, &QPushButton::clicked, this, &Content::onAmendBtnClicked);
    connect(CloseBtn, &QPushButton::clicked, this, &Content::onCloseBtnClicked);
    QHBoxLayout *BtnLayout = new QHBoxLayout;  //QHBoxLayou
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);

    //进行整体布局
    QVBoxLayout *RightLayout = new QVBoxLayout(this);  //主界面
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);
    RightLayout->addLayout(BtnLayout);
}

Content::~Content()
{
}

//修改按钮
void Content::onAmendBtnClicked(){

}
//关闭按钮
void Content::onCloseBtnClicked(){
    this->close();
}
