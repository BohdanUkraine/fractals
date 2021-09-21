#ifndef DRAWING_H
#define DRAWING_H

#include "mainwindow.h"

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter myline(this);
    myline.drawLine(1,1,1,1);
}


class coordinats{
public:
    int x;
    int y;
};

class line{

public:
    void draw(coordinats a, coordinats b){

    }

};



#endif // DRAWING_H
