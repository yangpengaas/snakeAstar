#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <list>
using namespace std;
struct Cube
{
public://f = g + h
    int f;//距离估计值
    int g;//该点到起点的距离
    int h;//该点到终点的估算值
    Cube* preCube;
};

class Astar
{
public:
    Astar(int w,int y);
    copyMap(Cube *newMap);
private:
    Cube **map;
    int width;
    int high;
    list<Cube> queue;

};

#endif // ASTAR_H
