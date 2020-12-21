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
	//void init();  doit �tre enlev�e car incluse dans la m�thode suivante
	void init(int val = 0);
	void init(Counter c);
	Counter add(Counter c);
};
