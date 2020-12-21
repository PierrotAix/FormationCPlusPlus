#ifndef OBSERVER_H
#define OBSERVER_H

class Subject; 

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void Update(Subject&) = 0;
};

#endif