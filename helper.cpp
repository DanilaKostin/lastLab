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
    lights.push_back(true);
    for (int i = 1; i < 100; i ++){
        lights.push_back(false);
    }
    //lights setting
    return lights;
}

