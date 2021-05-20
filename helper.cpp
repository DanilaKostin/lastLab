#include "helper.h"
#include <QDebug>

Helper::Helper(QObject *parent) : QObject(parent)
{

}
void Helper::dfs(int x, int y)
{
    int order[4] = {0,1,2,3};
    std::random_shuffle(order,order+4);
   // qDebug() <<  order[0] << order[1] << order[2] << order[3];
    for(int i = 0;i<4;i++)
    {
        if(order[i]==0 && y && p[x][y-1].empty())
        {
            p[x][y-1].push_back({x,y});
            dfs(x,y-1);
        }
        if(order[i]==1 && x && p[x-1][y].empty())
        {
            p[x-1][y].push_back({x,y});
            dfs(x-1,y);
        }
        if(order[i]==2 && y!=9 && p[x][y+1].empty())
        {
            p[x][y+1].push_back({x,y});
            dfs(x,y+1);
        }
        if(order[i]==3 && x!=9 && p[x+1][y].empty())
        {
            p[x+1][y].push_back({x,y});
            dfs(x+1,y);
        }
    }
}
QVector<int> Helper::newGame()
{
    QVector<int> bricks;
    for(int i = 0;i<100;i++) bricks.push_back(0);
    p[0][0].push_back({-1,-1});
    dfs(0,0);
    for(int i = 0;i<100;i++)
    {
        int x = i%10;
        int y = i/10;
        if(p[x][y][0]==qMakePair(x,y+1))
        {
            bricks[i]+=2;
            bricks[x+(y+1)*10]+=8;
        }
        if(p[x][y][0]==qMakePair(x+1,y))
        {
            bricks[i]+=1;
            bricks[(x+1)+(y)*10]+=4;
        }
        if(p[x][y][0]==qMakePair(x,y-1))
        {
            bricks[i]+=8;
            bricks[x+(y-1)*10]+=2;
        }
        if(p[x][y][0]==qMakePair(x-1,y))
        {
            bricks[i]+=4;
            bricks[(x-1)+(y)*10]+=1;
        }
        p[x][y].pop_back();
    }
    for(int i = 0;i<100;i++)
    {
        int tmp = rand()%4;
        for(int j = 0;j<tmp;j++)
            rotate(bricks[i]);
    }
    return bricks;
}
void Helper::rotate(int& a)
{
    a = ((a >> 1) | ((a&1) << 3));
}
//QVector<int> Helper::newGame(){
//    QVector<int> bricks = {
//        1, 5, 5, 5, 5, 5, 5, 5, 5, 6,
//        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
//        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
//        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
//        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
//        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
//        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
//        3, 5, 5, 5, 5, 5, 5, 5, 5, 12,
//        9, 5, 5, 5, 5, 5, 5, 5, 5, 6,
//        4, 5, 5, 5, 5, 5, 5, 5, 5, 12,
//    };
////generation

//    return bricks;

//}
QVector<bool> Helper::light(QVector<int> bricks){
    QVector<bool> lights;
    lights.push_back(true);

    for (int i = 1; i < 100; i ++)
    lights.push_back(false);

for(int g=0; g<100;g++){
    for (int b = 0; b <= 80; b+=10)
    for (int i = 0; i < 9; i++){
        if ((bricks.at(i+b) & 1) && (bricks.at(i+1+b) & 4) && ((lights.at(i+b) == true)||(lights.at(i+1+b) == true))){
        lights[i+b] = true;
        lights[i+1+b] = true;
        }
        if ((bricks.at(i+b) & 2) && (bricks.at(i+10+b) & 8) && ((lights.at(i+b) == true)||(lights.at(i+10+b) == true))){
        lights[i+b] = true;
        lights[i+10+b] = true;
        }
}

    for (int h = 0; h <9; h++)
    {
        if ((bricks.at(90 + h) & 8) && (bricks.at(80 + h)& 2) && ((lights.at(90+h) == true)||(lights.at(80+h) == true)))
        {
            lights[90 +h] = true;
            lights[80+h] = true;
        }
        if ((bricks.at(90 + h) & 1) && (bricks.at(90 + h + 1) & 4) && ((lights.at(90+h) == true)||(lights.at(90+h+1) == true)))
        {
            lights[90+h] = true;
            lights[90+h+1] = true;
        }

        if ((bricks.at(9 + h*10) & 2) && (bricks.at(19 + h*10)& 8) && ((lights.at(9+h*10) == true)||(lights.at(19+h*10) == true)))
        {
            lights[9 +h*10] = true;
            lights[19 +h*10] = true;
        }

    }
}
    if ((bricks.at(99) & 8) && (bricks.at(89) & 2) && ((lights.at(99) == true)||(lights.at(89) == true)))
    {
        lights[99] = true;
        lights[89] = true;
    }
    if ((bricks.at(99) & 4) && (bricks.at(98) & 1) && ((lights.at(99) == true)||(lights.at(98) == true)))
    {
        lights[99] = true;
        lights[98] = true;
    }
    return lights;
}

