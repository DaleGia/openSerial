#include "sensorControl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sensorControl w;
    w.show();

    return a.exec();
}
