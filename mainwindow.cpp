#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    Astar a(10,10);
    Cube **map;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            map[i][j].f= 0;
            map[i][j].g= 0;
            map[i][j].h= 0;
            map[i][j].x = i;
            map[i][j].y = j;
        }
    }
    a.copyMap(map);
    Cube src,dest;
    src.x=1;
    src.y=1;
    dest.x=5;
    dest.y=5;
    a.searchPath(src,dest);


}

MainWindow::~MainWindow()
{
    delete ui;
}
