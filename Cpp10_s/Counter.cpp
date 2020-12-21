#include <iostream>
#include "counter.h"

using namespace std;

Counter::Counter(): count(0)
{}

Counter::Counter(int a): count(a)
{}

Counter::Counter(long b): count(static_cast<int>(b))
{}

Counter::~Counter()
{
    //cout<<"execution du destructeur"<<endl;
}

Counter Counter::increment()
{
    count++;
    return *this;
}
void Counter::affiche()
{
    cout << "valeur: " << count << endl;
}

int Counter::lirecount()
{
    return count;
}

//void Counter::init() doit être enlevée car incluse dans la méthode suivante
//{
//    count=0;
//}
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

Counter Counter::add(Counter c)
{
    count += c.count;
    return *this;
}
