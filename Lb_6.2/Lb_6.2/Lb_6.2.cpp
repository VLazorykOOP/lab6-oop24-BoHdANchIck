#include <iostream>
using namespace std;

class Function
{
protected:
	double x;
public:
	Function() : x(0) {}
	Function(double _x) : x(_x) {}
	virtual double Funk() = 0;
};
class Line: public Function
{
	double a;
	double b;
public:
	Line(double _x, double _a, double _b) : Function(_x), a(_a), b(_b) {}
	virtual double Funk() override {
		return a * x + b;
	}
};

class Ellipse: public Function{
	double a, b;

public:
	Ellipse(double a, double b) : a(a), b(b) {}

	virtual double Funk() override {
		return std::sqrt(1 - (x * x) / (a * a)) * b;
	}
};

class Hyperbola : public Function {
	double a, b;

public:
	Hyperbola(double a, double b) : a(a), b(b) {}

	virtual double Funk() override {
		return std::sqrt(1 + (x * x) / (a * a)) * b;
	}
};

int main()
{
	double x = 2.0;

	Line line(2, 3, 4);
	Ellipse ellipse(5, 4);
	Hyperbola hyperbola(3, 2);

	cout << "Value of line at x = " << x << ": " << line.Funk() << endl;
	cout << "Value of ellipse at x = " << x << ": " << ellipse.Funk() << endl;
	cout << "Value of hyperbola at x = " << x << ": " << hyperbola.Funk() << endl;

	return 0;
}
