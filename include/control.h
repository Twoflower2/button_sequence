#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

/**
 * @class Control
 * @brief The Control class is where the game logic is implimented
 */
class Control : public QObject
{
    Q_OBJECT
    enum Color { kRed=1, kOrange, kGreen};
    enum LedNumber {kOne=0, kTwo,kThree};
    enum ButtonValue { kButtonA=1, kButtonB, kButtonC};

public:
    explicit Control(QObject *parent = nullptr);
    void generateSequence();
    void validateButtonSequence(int value);
    bool isSequenceValue(const int buttonValue);
    void getGameSequence(const int gameArray[]);

 signals:
    void setLed1(int Color);
    void setLed2(int Color);
    void setLed3(int Color);
    void setHint(QString hintText);

 public slots:
    void validateButtonA();
    void validateButtonB();
    void validateButtonC();

 private:
    /**
     * @brief generated_sequence stores the random generated sequence of
     *        buttons pressed. The button number of the pressed button
     *        is stored in the array as value where first, second or
     *        third pressed is the element position in the array.
     */
    int m_generated_sequence[3];
    int m_game_sequence[3] = {0, 0, 0};
    int m_led_history[3] = {Color::kRed, Color::kRed, Color::kRed};
    int m_sequence;
    long m_clicks = 0;

};

#endif // CONTROL_H
