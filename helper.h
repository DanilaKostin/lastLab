//#ifndef HELPER_H
//#define HELPER_H

//#include <QObject>
//#include <QVector>

//class Helper : public QObject
//{
//    Q_OBJECT
//public:
//    explicit Helper(QObject *parent = nullptr);

//signals:

//public slots:
//    QVector<int> newGame();
//    QVector<bool> light(QVector<int> bricks);

//};

//#endif // HELPER_H

#ifndef HELPER_H
#define HELPER_H
#include <QVector>
#include <QObject>
#include <utility>
class Helper : public QObject
{
Q_OBJECT

public:

explicit Helper(QObject *parent = nullptr);

signals:
public slots:
QVector<int> newGame();

QVector<bool> light(QVector<int> bricks);
private:
void dfs(int x,int y);
QVector<QPair<int,int>> p[12][12];
void rotate(int& a);
};
#endif // HELPER_H
