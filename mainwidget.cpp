#include "mainwidget.h"
#include <QWidget>
using namespace std;

void mainwidget::paintEvent(QPaintEvent *event, int x1, int y1, int x2, int y2)
{
    QPainter painter(this);

    painter.drawLine(x1,y1,x2,y2);
}
