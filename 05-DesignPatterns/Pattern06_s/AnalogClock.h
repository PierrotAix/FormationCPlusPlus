#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <iostream>
#include "ClockTimer.h"

class AnalogClock : public Observer
{
private:
    ClockTimer& subject;

public:
    explicit AnalogClock(ClockTimer& s);
    
    ~AnalogClock();
    
    void Update(Subject& theChangedSubject) override;
    
    void Draw();

};

#endif