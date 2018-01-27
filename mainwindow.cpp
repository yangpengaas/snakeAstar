#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#if 0
    list<int> b;
    b.push_back(32);
    b.push_back(2);
    b.push_back(3);
    b.push_back(32);
    b.push_back(12);
    b.push_back(16);
    b.push_back(15);
    b.push_back(19);
    b.sort();
    list<int>::iterator iter;
    int i=0;
    for(iter=b.begin();iter!=b.end();iter++)
    {
        cout << "b[" << i++ << "]:" << *iter << endl;
    }
    #endif
    Astar a(10,10);
    Cube **map;
    for(int i=0; i<10; i++)
    {
        map[i] = new Cube[10];
        for(int j=0; j<10; j++)
        {
            //qDebug("(%d,%d)\n",i,j);
            map[i][j].f= 0;
            map[i][j].g= 0;
            map[i][j].h= 0;
            map[i][j].point.x = i;
            map[i][j].point.y = j;
        }
    }
    a.copyMap(map);
    Cube src,dest;
    src.point.x=0;
    src.point.y=0;
    dest.point.x=4;
    dest.point.y=4;
    int ret = a.searchPath(src,dest);
    qDebug() << "ret:" << ret <<endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}
