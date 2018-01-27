#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <list>
#include <QPoint>
using namespace std;

#define test
struct Cube
{
public://f = g + h
    int f;//距离估计值
    int g;//该点到起点的距离
    int h;//该点到终点的估算值
    int x,y;
    int pre;
};

class Astar
{
public:
    Astar(int w,int y);
    void copyMap(Cube **newMap);
    int searchPath(Cube src,Cube dest);
    void insertList(Cube );
private:
    Cube **map;
    int width;
    int high;
    list<int> aStarList;
    list<int>::iterator iter;

};

#endif // ASTAR_H
