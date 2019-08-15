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

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(m_led_3_text);
    verticalLayout->addWidget(m_led_3);
    verticalLayout->addWidget(m_led_2_text);
    verticalLayout->addWidget(m_led_2);
    verticalLayout->addWidget(m_led_1_text);
    verticalLayout->addWidget(m_led_1);

    QHBoxLayout *horizontallayout = new QHBoxLayout;
    horizontallayout->addItem(verticalLayout);
    horizontallayout->addWidget(m_button_a);
    horizontallayout->addWidget(m_button_b);
    horizontallayout->addWidget(m_button_c);
    horizontallayout->addWidget(m_label_hint);
    QVBoxLayout *verticalLayout1 = new QVBoxLayout;
    horizontallayout->addItem(verticalLayout1);

    setLayout(horizontallayout);

    setWindowTitle(tr("3 Button chooce"));
    resize(800, 600);

    connect(m_button_a, &QPushButton::clicked, m_control, &Control::validateButtonA);
    connect(m_button_b, &QPushButton::clicked, m_control, &Control::validateButtonB);
    connect(m_button_c, &QPushButton::clicked, m_control, &Control::validateButtonC);
    //connect(m_button_exit, &QPushButton::clicked, this, doExit);

    connect(m_control, &Control::setLed1, m_led_1, &Led::setColor);
    connect(m_control, &Control::setLed2, m_led_2, &Led::setColor);
    connect(m_control, &Control::setLed3, m_led_3, &Led::setColor);
    connect(m_control, &Control::setHint, m_label_hint, &QLabel::setText);
}

SequenceWindow::~SequenceWindow()
{
}

void SequenceWindow::doExit()
{

}
