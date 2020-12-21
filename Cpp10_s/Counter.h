#pragma once
class Counter
{
private:
	int count;

public:
	Counter();
	Counter(int a);
	Counter(long b);
	~Counter();
	Counter increment();
	void affiche();
	int lirecount();
	//void init();  doit être enlevée car incluse dans la méthode suivante
	void init(int val = 0);
	void init(Counter c);
	Counter add(Counter c);
};
