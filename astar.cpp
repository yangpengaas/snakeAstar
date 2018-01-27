#include "astar.h"

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
Astar::Astar(int w,int h):width(w),high(h)
{

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
            map[i][j].point.x = i;
            map[i][j].point.y = j;
            map[i][j].istouch = false;
        }
    }
}
void Astar::insertList(Cube cube)
{
    int flag = 0;
    if(aStarList.empty())
    {
        aStarList.push_back(&cube);
        return;
    }
    for(iter = aStarList.begin();iter!=aStarList.end();iter++)
    {
        if((*iter)->f > cube.f)
        {
            flag = 1;
            aStarList.insert(iter,&cube);
        }
        if(((*iter)->point.x == cube.point.x)&&(*iter)->point.y == cube.point.y)
            flag = 1;

    }
    if(flag == 0)
    {
        aStarList.push_back(&cube);
    }
}
int Astar::searchPath(Cube src, Cube dest)
{
    Cube *temp;
    int x,y,tempnum;

    aStarList.push_back(&map[src.point.x][src.point.y]);


    while(true)
    {
        aStarList.unique();
        temp = aStarList.front();
        aStarList.pop_front();

        for(int i=0; i<4; i++)
        {
            x = temp->point.x + dir[i][0];
            y = temp->point.y + dir[i][1];
            if((x==dest.point.x)&&(y==dest.point.y))
                return 1;
            if((x>=0) && (x<width) && (y>=0) && (y<high))
            {

                map[x][y].g = qAbs(x-src.point.x)+ qAbs(y-src.point.y);
                 map[x][y].h = qAbs(dest.point.x-x) +qAbs(dest.point.y-y);
                map[x][y].f = map[x][y].g + map[x][y].h;
                map[x][y].pre = temp;
                insertList(map[x][y]);

            }
            else
                continue;

            cout << "x:" << x << "y:" << y << endl;

        }

    }

}







