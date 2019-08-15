#include "sequencewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SequenceWindow w;
    w.show();

    return a.exec();
}
