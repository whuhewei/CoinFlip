#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString btnImg);

    int posX;
    int poxY;
    bool flag;

    void changeFlag();
    QTimer * timer1;
    QTimer * timer2;
    int min = 1;
    int max = 8;
signals:

};

#endif // MYCOIN_H
