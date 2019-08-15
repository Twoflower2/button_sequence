#include <led.h>
#include <QPainter>

Led::Led(QWidget *parent) : QWidget(parent) {
    m_led_color = LedColor::kRed;
}

int Led::getColor()
{
    return m_led_color;
}

void Led::setColor(int ledColor) {
    m_led_color = static_cast<LedColor>(ledColor);
    update();
}

void Led::doSetColor() {
    emit colorChanged(LedColor::kGreen);
}

void Led::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter ledPainter(this);
    ledPainter.setPen(Qt::black);
    if (m_led_color == LedColor::kRed) {
        ledPainter.setBrush(Qt::red);
    } else if (m_led_color == LedColor::kOrange) {
        QColor orangeColor(255,165,0);
        ledPainter.setBrush(orangeColor);
    } else if (m_led_color == LedColor::kGreen) {
        ledPainter.setBrush(Qt::green);
    }
    QRectF rectangle(0, 0, 50.0, 50.0);
    ledPainter.drawEllipse(rectangle);
}
