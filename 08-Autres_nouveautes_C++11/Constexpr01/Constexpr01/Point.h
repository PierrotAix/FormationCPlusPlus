class Point {
public:
	Point(double xVal = 0, double yVal = 0) 
		: x(xVal), y(yVal)
	{}

	double xValue() const  { return x; }
	double yValue() const  { return y; }

	void setX(double newX)  { x = newX; }
	void setY(double newY)  { y = newY; }


private:
	double x, y;
};

