class Counter
{
private:
	int count;
	static int nbcounter; // variable de classe

public:
	Counter();
	Counter(int a);
	Counter(long b);
	Counter(const Counter&);
	~Counter();
	Counter& increment();
	void affiche() const;
	int lirecount() const;
	void init(int val = 0);
	void init(const Counter& c);
	Counter& add(const Counter& c);
	operator int() const;
	Counter& operator= (const Counter&);
	friend Counter operator+(const Counter& c1, const Counter& c2);
	friend Counter& operator+=(Counter& c1, const Counter& c2);
	static int lirenbcounter();
};

