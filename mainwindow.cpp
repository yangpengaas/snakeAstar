#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<int> a;
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
