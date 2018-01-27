#include "astar.h"

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
Astar::Astar(int w,int h)
{
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<h; j++)
        {
            map[i][j] = Cube();
        }
    }

}

void Astar::copyMap(Cube ** newMap)
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<high; j++)
        {
            map[i][j].f= newMap[i][j].f;
            map[i][j].g= newMap[i][j].g;
            map[i][j].h= newMap[i][j].h;
            map[i][j].x = i;
            map[i][j].y = j;
        }
    }
}
void Astar::insertList(Cube cube)
{
    for(iter = aStarList.begin();iter!=aStarList.end();iter++)
    {

    }
}
int Astar::searchPath(Cube src, Cube dest)
{
    Cube temp;
    int x,y,tempnum;
    aStarList.push_back(src.x + src.y);


    while(true)
    {
        tempnum = aStarList.front();
        aStarList.pop_front();
        for(int i=0; i<4; i++)
        {
            x = tempnum/width + dir[i][0];
            y = tempnum%width + dir[i][1];
            if((x==dest.x)&&(y==dest.y))
                return 1;
            if((x>=0) && (x<width) && (y>=0) && (y<high))
                continue;
            else
            {
                aStarList.push_back(x+y);
                map[x][y].g = map[tempnum/width][tempnum%width].g+1;
                map[x][y].h = dest.x-x +dest.y -y;
                map[x][y].f = map[x][y].g + map[x][y].h;
                map[x][y].pre = tempnum;

            }
            cout << "x:" << x << "y:" << y << endl;
            aStarList.sort();
            aStarList.unique();
        }

    }

}







