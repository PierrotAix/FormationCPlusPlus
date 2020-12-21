#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject
{
private:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() = default;
    void Attach(Observer& o);
    void Detach(Observer& o);
    void Notify();

};

#endif
