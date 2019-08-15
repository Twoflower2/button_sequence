#include <QRandomGenerator>
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
    int sequenceIndex;
    //reset LEDs back to red
    if (m_sequence == 3) {
        for (int it = 0; it < 3; ++it) {
            m_led_history[it] = Color::kRed;
        }
    }
    //when sequence matches generate new computer sequence
    if ((m_generated_sequence[0] == m_game_sequence[0]) and
            (m_generated_sequence[1] == m_game_sequence[1]) and
            (m_generated_sequence[2] == m_game_sequence[2]) and
            m_sequence == 3) {
        generateSequence();
        for (int it = 0; it < 3; ++it) {
            m_game_sequence[it] = 0;
        }
    }
    //update sequence marker
    if (m_sequence < 3) {
        ++m_sequence;
    } else {
        m_sequence = 1;
    }
    sequenceIndex = m_sequence - 1;
    m_game_sequence[sequenceIndex] = buttonValue;
    ++m_clicks;
    //move LED colour history to other LEDs
    if (m_clicks > 2) {
        m_led_history[LedNumber::kOne] = m_led_history[LedNumber::kTwo];
        m_led_history[LedNumber::kTwo] = m_led_history[LedNumber::kThree];
    } else if (m_clicks > 1){
        m_led_history[LedNumber::kTwo] = m_led_history[LedNumber::kThree];
    }
    //set current LED after sequence choice
    if (isSequenceValue(buttonValue)) {
        if (buttonValue == m_generated_sequence[sequenceIndex]) {
            m_led_history[LedNumber::kThree] = Color::kGreen;
        } else {
            m_led_history[LedNumber::kThree] = Color::kOrange;
        }
    } else {
        m_led_history[LedNumber::kThree] = Color::kRed;
    }

    emit setLed1(m_led_history[LedNumber::kOne]);
    emit setLed2(m_led_history[LedNumber::kTwo]);
    emit setLed3(m_led_history[LedNumber::kThree]);
    emit setHint("( Hint: The last clicked sequence was " + QString::number(m_sequence) + " out of 3)");
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

