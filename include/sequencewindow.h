/**
 * @headerfile sequencewindow.h
 *
 * @brief SequenceWindow class header file
 *
 * @author Pierre Ludwick
 * @date 15AUG2019
 * @copyright GNU Public License
 *
 */
#ifndef SEQUENCEWINDOW_H
#define SEQUENCEWINDOW_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QLabel>
#include <led.h>
#include <control.h>

/**
 * @class SequenceWindow
 * @brief The SequenceWindow class creates the appl. window
 */
class SequenceWindow : public QWidget {
  Q_OBJECT

 public:
  explicit SequenceWindow(QWidget *parent = nullptr);
  ~SequenceWindow();
 private slots:


 private:
  Led *m_led_1;
  Led *m_led_2;
  Led *m_led_3;
  QLabel *m_led_1_text;
  QLabel *m_led_2_text;
  QLabel *m_led_3_text;
  QPushButton *m_button_a;
  QPushButton *m_button_b;
  QPushButton *m_button_c;
  QLabel *m_label_hint;
  Control *m_control;
};

#endif // SEQUENCEWINDOW_H
