/**
 * @file main.cc
 *
 * @brief main function implimentation
 *
 * @author Pierre Ludwick
 * @date 15AUG2019
 * @copyright GNU Public License
 *
 */
#include "sequencewindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  SequenceWindow w;
  w.show();

  return a.exec();
}
