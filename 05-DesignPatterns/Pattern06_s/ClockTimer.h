#ifndef CLOCKTIMER_H
#define CLOCKTIMER_H

#include "Subject.h"

class ClockTimer : public Subject
{
private:
    int hour;
    int minute;
    int second;

public:

    void SetTime(int hour, int minute, int second);

    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
};

#endif