#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
#include <QGraphicsScene>
#define x first
#define y second
using namespace std;

int r = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

template<typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}

class fractal{

public:
    vector<pair<int, int>> make_fractal_koh(vector<pair<int, int>> l, int iteration){

        vector<pair<int, int>> l1;
        pair<int, int> a,b,c,d,e;

        for (int jj=0; jj<iteration; jj++){

            if(jj+1 % 2 != 0){
                l=reverse(l);
            }

            a = l.back();
            l.pop_back();

            while(!l.empty()){

                b = l.back();
                l.pop_back();

                c.x = (2*a.x+b.x)/3;
                c.y = (2*a.y+b.y)/3;

                d.x = (a.x+2*b.x)/3;
                d.y = (a.y+2*b.y)/3;

                e = get_e_koh(a,b);

                l1.push_back(a);
                l1.push_back(c);
                l1.push_back(e);
                l1.push_back(d);
                l1.push_back(b);

                a = b;


            }

            l=l1;
            l1.clear();

        }

        return l;

    }

    vector<pair<int, int>> make_fractal_lewis(vector<pair<int, int>> l, int iteration){

        vector<pair<int, int>> l1;
        pair<int, int> a,b,c;

        for (int jj=0; jj<iteration; jj++){


            if(jj+1 % 2 != 0){
                l=reverse(l);
            }


            a = l.back();
            l.pop_back();

            while(!l.empty()){

                b = l.back();
                l.pop_back();

                c.x = ((a.x+b.x)/2) + ((b.y-a.y)/2);
                c.y = ((a.y+b.y)/2) - ((b.x-a.x)/2);

                l1.push_back(a);
                l1.push_back(c);
                l1.push_back(b);

                a = b;

            }

            l=l1;
            l1.clear();

        }

        return l;

    }


    void make_fractal_pif(pair<int, int> arr[9999], int iteration){

        for (int i = 0;  i < 5*(pow(2, iteration) - 1);  i += 5)
        {
            Traf(arr, arr[i].x, arr[i].y, arr[i+1].x, arr[i+1].y, 5*r);

            Traf(arr, arr[i+1].x, arr[i+1].y, arr[i+2].x, arr[i+2].y, 5*(r+1));

            r = r + 2;
        }

    }


private:

    void Traf(pair<int, int> arr[], double xA, double yA, double xB, double yB, int r)
          {
             arr[r + 4].x = xA;   arr[r + 4].y = yA;
             arr[r + 3].x = xB;   arr[r + 3].y = yB;
             double xC = arr[r].x = xA + yA - yB;
             double yC = arr[r].y = yA + xB - xA;
             double xD = arr[r + 2].x = xB + yA - yB;
             double yD = arr[r + 2].y = yB + xB - xA;
             arr[r + 1].x = (xC + xD + (yC - yD))/(2);
             arr[r + 1].y = (yC + yD + (xD - xC))/(2);
          }

    pair<int, int> get_e_koh (pair<int, int> a, pair<int, int> b)
        {
            pair<int, int> e;

            e.x = ((a.x+b.x)/2) + ((a.y-b.y)/(2*sqrt(3)));
            e.y = ((a.y+b.y)/2) + ((b.x-a.x)/(2*sqrt(3)));

            return e;
        }

    vector<pair<int, int>> reverse(vector<pair<int, int>> l){

        vector<pair<int, int>> l1;
        pair<int, int> a;

        for(int i=l.size()-1; i>=0; i--){
            a = l.back();
            l1.push_back(a);
            l.pop_back();
        }

        return l1;
    }

};

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int fraktal=0;
    int i;
    vector<pair<int, int>> l;
    pair<int, int> b;

    cout << "Menu\n" << "Choose a number:\n" << "1) Koh's fractal\n" << "2)Piphagor's tree\n" << "3)Lewi's fractal\n";
    cin >> fraktal;

    cout << "Enter iteration (Default = 1):\n";
    cin >> i;

    if (i <= 0) i = 1;


    //fractal koha
    if(fraktal == 1){


    fractal koh;

    b.x = 100;
    b.y = 300;

    l.push_back(b);

    b.x = 500;
    b.y = 300;

    l.push_back(b);
    l = koh.make_fractal_koh(l,i);

    pair<int, int> a;

    a = l.back();
    l.pop_back();

    while(!l.empty()){

        b = l.back();
        l.pop_back();

        //drawing
        painter.drawLine(a.x,a.y,b.x,b.y);

        a=b;
    }
    }
    else if(fraktal == 2){
        //frctal piphagora

        fractal pif;


        pair<int, int> arr[99999];

        arr[0].x = 300;
        arr[0].y = 0;

        arr[1].x = 400;
        arr[1].y = 0;

        pif.make_fractal_pif(arr,i);


            painter.drawLine(arr[3].x, arr[3].y   ,   arr[4].x, arr[4].y);

        for (int i=0; i<5*r; i+=5){

           painter.drawLine(arr[i].x, arr[i].y   ,   arr[i+1].x, arr[i+1].y);
           painter.drawLine(arr[i].x, arr[i].y   ,   arr[i+2].x, arr[i+2].y);
           painter.drawLine(arr[i+1].x, arr[i+1].y , arr[i+2].x, arr[i+2].y);
           painter.drawLine(arr[i+2].x, arr[i+2].y , arr[i+3].x, arr[i+3].y);
           painter.drawLine(arr[i+4].x, arr[i+4].y   ,   arr[i].x, arr[i].y);

        }

    }
    else if(fraktal == 3){
        //frctal lewisa

        fractal lewis;

        b.x = 200;
        b.y = 300;

        l.push_back(b);

        b.x = 400;
        b.y = 300;

        l.push_back(b);
        l = lewis.make_fractal_lewis(l,i);

        pair<int, int> a;

        a = l.back();
        l.pop_back();

        while(!l.empty()){

            b = l.back();
            l.pop_back();

            //drawing
            painter.drawLine(a.x,a.y,b.x,b.y);

            a=b;
        }

    }



}

