#include "Counter.h"
#include <iostream>

using namespace std;

Counter::Counter(): count(0)
{}

Counter::Counter(int a): count(a)
{}

Counter::Counter(long b): count(static_cast<int>(b))
{}

Counter::~Counter()
{
    cout << "execution du destructeur" << endl;
}

void Counter::increment()
{
    count++;
}

void Counter::affiche()
{
    cout << "valeur: " << count << endl;
}

int Counter::lirecount()
{
    return count;
}
void Counter::init()
{
    count = 0;
}

void Counter::init(int val)
{
    count = val;
}

void Counter::init(Counter c)
{
    //count=c.lirecount();
    //init(c.count);
    count = c.count;
}

