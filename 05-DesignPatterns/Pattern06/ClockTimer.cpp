#include "ClockTimer.h"

void ClockTimer::SetTime(int hour, int minute, int second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;

    Notify();
}

int ClockTimer::GetHour() const { 
    return hour; 
}

int ClockTimer::GetMinute() const { 
    return minute; 
}

int ClockTimer::GetSecond() const { 
    return second; 
}