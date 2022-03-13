#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString normalImg, QString pressImg = "");

    QString normalImgPath;
    QString pressImgPath;

    void zoom1();
    void zoom2();
signals:

};

#endif // MYPUSHBUTTON_H
