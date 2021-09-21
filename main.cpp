#include "mainwindow.h"
#include "mainwindow.cpp"

#include <QApplication>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication appp(argc, argv);
    MainWindow w;

    w.show();
    return appp.exec();
}
