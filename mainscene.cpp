#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"

#include <QPainter>
#include <QTimer>
#include <QSoundEffect>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("CoinFlip");

    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    QSoundEffect * startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));

    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);

    chooseScene = new ChooseLevelScene;

    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=](){
        this->setGeometry(chooseScene->geometry());

        chooseScene->hide();
        this->show();
    });

    connect(startBtn, &QPushButton::clicked, [=](){
        startSound->play();


        startBtn->zoom1();
        startBtn->zoom2();

        QTimer::singleShot(500, this, [=](){
            chooseScene->setGeometry(this->geometry());

            this->hide();
            chooseScene->show();
        });
    });
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix);
}

MainScene::~MainScene()
{
    delete ui;
}
