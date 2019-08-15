/**
 * @file sequencewindow.cc
 *
 * @brief SequenceWindow class implimentation
 *
 * @author Pierre Ludwick
 * @date 15AUG2019
 * @copyright GNU Public License
 *
 */
#include <sequencewindow.h>

SequenceWindow::SequenceWindow(QWidget *parent) :
  QWidget(parent) {
  m_led_1 = new Led();
  m_led_2 = new Led();
  m_led_3 = new Led();
  m_led_1_text = new QLabel("LED 1");
  m_led_2_text = new QLabel("LED 2");
  m_led_3_text = new QLabel("LED 3");

  m_button_a = new QPushButton("&A");
  m_button_b = new QPushButton("&B");
  m_button_c = new QPushButton("&C");
  m_label_hint = new QLabel;
  m_control = new Control;

  this->setMinimumSize(600,400);

  QHBoxLayout *horizontallayout = new QHBoxLayout;
  QVBoxLayout *verticalLayout = new QVBoxLayout;
  verticalLayout->setMargin(15);
  verticalLayout->addWidget(m_led_3_text);
  verticalLayout->setSpacing(1);
  verticalLayout->addWidget(m_led_3);
  verticalLayout->addWidget(m_led_2_text);
  verticalLayout->addWidget(m_led_2);
  verticalLayout->addWidget(m_led_1_text);
  verticalLayout->addWidget(m_led_1);
  horizontallayout->addItem(verticalLayout);

  QVBoxLayout *verticalLayout1 = new QVBoxLayout;
  QHBoxLayout *horizontallayout1 = new QHBoxLayout;
  verticalLayout1->addStretch(50);
  horizontallayout1->addWidget(m_button_a);
  horizontallayout1->addSpacing(5);
  horizontallayout1->addWidget(m_button_b);
  horizontallayout1->addSpacing(5);
  horizontallayout1->addWidget(m_button_c);
  verticalLayout1->addItem(horizontallayout1);
  verticalLayout1->addSpacing(10);
  verticalLayout1->addWidget(m_label_hint);
  horizontallayout->addItem(verticalLayout1);
  setLayout(horizontallayout);

  setWindowTitle(tr("3 Button chooce"));
  resize(800, 600);

  connect(m_button_a, &QPushButton::clicked, m_control,
    &Control::validateButtonA);
  connect(m_button_b, &QPushButton::clicked, m_control,
    &Control::validateButtonB);
  connect(m_button_c, &QPushButton::clicked, m_control,
    &Control::validateButtonC);
  connect(m_control, &Control::setLed1, m_led_1, &Led::setColor);
  connect(m_control, &Control::setLed2, m_led_2, &Led::setColor);
  connect(m_control, &Control::setLed3, m_led_3, &Led::setColor);
  connect(m_control, &Control::setHint, m_label_hint, &QLabel::setText);
}

SequenceWindow::~SequenceWindow() {
  delete m_led_1;
  delete m_led_2;
  delete m_led_3;
  delete m_led_1_text;
  delete m_led_2_text;
  delete m_led_3_text;
  delete m_button_a;
  delete m_button_b;
  delete m_button_c;
  delete m_label_hint;
  delete m_control;
}
