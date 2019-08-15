#include <QRandomGenerator>
#include <QtDebug>
#include <control.h>

Control::Control(QObject *parent) : QObject(parent)
{
    generateSequence();
}

void Control::generateSequence(){
    m_generated_sequence[0] = QRandomGenerator::global()->bounded(3) + 1;
    m_generated_sequence[1] = QRandomGenerator::global()->bounded(3) + 1;
    m_generated_sequence[2] = QRandomGenerator::global()->bounded(3) + 1;
    m_sequence = 0;
    m_clicks = 0;
}

void Control::validateButtonSequence(int buttonValue)
{
    qDebug() << "-----------------------------";
    qDebug() << "button pressed: " << buttonValue;
    int sequenceIndex;
    if (m_sequence == 3) {
        for (int it = 0; it < 3; ++it) {
            m_led_history[it] = Color::kRed;
        }
    }
    if ((m_generated_sequence[0] == m_game_sequence[0]) and
            (m_generated_sequence[1] == m_game_sequence[1]) and
            (m_generated_sequence[2] == m_game_sequence[2]) and
            m_sequence == 3) {
        generateSequence();
        for (int it = 0; it < 3; ++it) {
            m_game_sequence[it] = 0;
        }
    }
    if (m_sequence < 3) {
        ++m_sequence;
    } else {
        m_sequence = 1;
    }
    sequenceIndex = m_sequence - 1;
    m_game_sequence[sequenceIndex] = buttonValue;
    ++m_clicks;
    qDebug() << ">>>> m_sequence = " << m_sequence << " m_clicks=" <<m_clicks;

    for (int it = 0; it < 3; ++it) {
        qDebug() << "m_game_sequence[it]="<<m_game_sequence[it]<< "; m_generated_sequence[it]=" << m_generated_sequence[it];
    }
    //move LED colour history to other LEDs
    if (m_clicks > 2) {
        m_led_history[LedNumber::kOne] = m_led_history[LedNumber::kTwo];
        m_led_history[LedNumber::kTwo] = m_led_history[LedNumber::kThree];
    } else if (m_clicks > 1){
        m_led_history[LedNumber::kTwo] = m_led_history[LedNumber::kThree];
    }

    if (isSequenceValue(buttonValue)) {
        if (buttonValue == m_generated_sequence[sequenceIndex]) {
            m_led_history[LedNumber::kThree] = Color::kGreen;
        } else {
            m_led_history[LedNumber::kThree] = Color::kOrange;
        }
    } else {
        m_led_history[LedNumber::kThree] = Color::kRed;
    }

    //Iterate over generated sequence and check against game value, setting the last used LED (3) colour.

    qDebug() << "m_led_history[LedNumber::kThree] = " << m_led_history[LedNumber::kThree];
    emit setLed1(m_led_history[LedNumber::kOne]);
    emit setLed2(m_led_history[LedNumber::kTwo]);
    emit setLed3(m_led_history[LedNumber::kThree]);
    emit setHint("( Hint: The last clicked sequence was " + QString::number(m_sequence) + " out of 3)");
    qDebug() << "-----------------------------";
}

bool Control::isSequenceValue(const int buttonValue)
{
    for (int seqIndex = 0; seqIndex < 3; ++seqIndex) {
        if (buttonValue == m_generated_sequence[seqIndex]) {
            return true;
        }
    }
    return false;
}

void Control::validateButtonA()
{
    validateButtonSequence(ButtonValue::kButtonA);
}

void Control::validateButtonB()
{
    validateButtonSequence(ButtonValue::kButtonB);
}

void Control::validateButtonC()
{
    validateButtonSequence(ButtonValue::kButtonC);
}

