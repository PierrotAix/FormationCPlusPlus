#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <iostream>
#include "ClockTimer.h"

class DigitalClock : public Observer
{
private:
    ClockTimer& subject;

public:
    explicit DigitalClock(ClockTimer& s);
    
    ~DigitalClock();
    
    void Update(Subject& theChangedSubject) override;

    void Draw();

};

#endif