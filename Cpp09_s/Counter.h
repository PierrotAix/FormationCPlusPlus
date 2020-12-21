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
	//void init();
	void init(int val = 0); // valeur par défaut
	void init(Counter c);
};

