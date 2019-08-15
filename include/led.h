#ifndef LEDCOLOR_H
#define LEDCOLOR_H

#include <QWidget>


class Led : public QWidget {
    Q_OBJECT
    enum LedColor { kRed=1, kOrange, kGreen};

public:
    explicit Led(QWidget *parent = nullptr);
    int getColor();

 signals:
    void colorChanged(LedColor color);

 public slots:
    void setColor(int ledColor);
    void doSetColor();

 protected:
    virtual void paintEvent(QPaintEvent* event) override;

 private:
    LedColor m_led_color;
};

#endif // LEDCOLOR_H
