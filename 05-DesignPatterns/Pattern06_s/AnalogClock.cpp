#include "AnalogClock.h"

AnalogClock::AnalogClock(ClockTimer& s) : subject(s) { 
    subject.Attach(*this); 
}

AnalogClock::~AnalogClock() { 
    subject.Detach(*this); 
}

void AnalogClock::Update(Subject& theChangedSubject){
    if (&theChangedSubject == &subject) {
        Draw();
    }
}

void AnalogClock::Draw(){
    int hour = subject.GetHour();
    int minute = subject.GetMinute();
    int second = subject.GetSecond();

    std::cout << "Analog time is " << hour << ":"
        << minute << ":"
        << second << std::endl;
}