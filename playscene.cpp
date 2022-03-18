#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第%1关").arg(levelNum);
    qDebug() << str;
    this->levelIndex = levelNum;

    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币场景");

    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &MyPushButton::clicked, [=](){
        qDebug() << "翻金币场景中点击了返回";
        QTimer::singleShot(500, this, [=](){
            emit this->chooseSceneBack();
        });
    });
}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
