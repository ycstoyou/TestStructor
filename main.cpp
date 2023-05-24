#include "TesetView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TesetView w;
    w.show();
    return a.exec();
}
