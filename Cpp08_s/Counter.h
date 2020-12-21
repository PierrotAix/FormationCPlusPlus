#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
	int count;

public:
	Counter();
	Counter(int a);
	Counter(long b);
	~Counter();
	void increment();
	void affiche();
	int lirecount();
	void init();
	void init(int val);
	void init(Counter c);
};

#endif
