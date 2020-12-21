
#include "DigitalClock.h"

DigitalClock::DigitalClock(ClockTimer& s) : subject(s) {
    subject.Attach(*this);
}

DigitalClock::~DigitalClock() {
    subject.Detach(*this);
}

void DigitalClock::Update(Subject& theChangedSubject) {
    if (&theChangedSubject == &subject) {
        Draw();
    }
}

void DigitalClock::Draw() {
    int hour = subject.GetHour();
    int minute = subject.GetMinute();
    int second = subject.GetSecond();

    std::cout << "Digital time is " << hour << ":"
        << minute << ":"
        << second << std::endl;
}