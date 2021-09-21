#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
class mainwidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainwidget();
    ~mainwidget();

    void paintEvent(QPaintEvent *event, int x1, int y1, int x2, int y2);
};

#endif // MAINWIDGET_H
