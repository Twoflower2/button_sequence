#ifndef LEDCOLOR_H
#define LEDCOLOR_H

#include <QWidget>

/**
  * @class Led
 * @brief The Led class used as custom widget for LEDs
 */
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
    /**
     * @brief paintEvent override to create LED shaped as circle
     * @param event
     */
    virtual void paintEvent(QPaintEvent* event) override;

 private:
    LedColor m_led_color;
};

#endif // LEDCOLOR_H
