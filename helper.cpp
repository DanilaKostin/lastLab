#include "helper.h"
#include <QDebug>
Helper::Helper(QObject *parent) : QObject(parent)
{

}

QVector<int> Helper::newGame(){
    QVector<int> bricks = {
        1, 5, 5, 5, 5, 5, 5, 5, 5, 6,
        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
        4, 5, 5, 5, 5, 5, 5, 5, 5, 12,
    };
//generation

    return bricks;

}
QVector<bool> Helper::light(QVector<int> bricks){
    QVector<bool> lights;
    //lights.push_back(true);

    for (int i = 0; i < 100; i ++)
    lights.push_back(false);

    for (int b = 0; b <= 80; b+=10)
    for (int i = 0; i < 9; i++){
        if ((bricks.at(i+b) & 1) && (bricks.at(i+1+b) & 4)){
        lights[i+b] = true;
        lights[i+1+b] = true;
        }
        if ((bricks.at(i+b) & 2) && (bricks.at(i+10+b) & 8)){
        lights[i+b] = true;
        lights[i+10+b] = true;
        }
}
    for (int h = 0; h <8; h++)
    {
        if ((bricks.at(90 + h) & 8) && (bricks.at(80 + h)& 2))
        {
            lights[90 +h] = true;
            lights[80+h] = true;
        }
        if ((bricks.at(90 + h) & 1) && (bricks.at(90 + h + 1) & 4))
        {
            lights[90+h] = true;
            lights[90+h+1] = true;
        }

        if ((bricks.at(9 + h*10) & 2) && (bricks.at(19 + h*10)& 8))
        {
            lights[9 +h*10] = true;
            lights[19 +h*10] = true;
        }

    }
    if ((bricks.at(99) & 8) && (bricks.at(89) & 2))
    {
        lights[99] = true;
        lights[89] = true;
    }
    if ((bricks.at(99) & 4) && (bricks.at(98) & 1))
    {
        lights[99] = true;
        lights[98] = true;
    }
    return lights;
}

