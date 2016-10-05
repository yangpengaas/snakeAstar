#include "astar.h"

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

Astar::copyMap(Cube ** newMap)
{
    for(int i=w; i<w; i++)
    {
        for(int j=0; j<h; j++)
        {
            map[i][j].f= newMap[i][j].f;
            map[i][j].g= newMap[i][j].g;
            map[i][j].h= newMap[i][j].h;
        }
    }
}



