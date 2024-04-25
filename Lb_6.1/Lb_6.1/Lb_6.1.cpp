#include <iostream>
#include <string>
class Base
{
protected:
	int dat;
public:
	Base() : dat(1) {}
	Base(int d) : dat(d) {}
};

class D1 : protected Base
{
protected:
	int d1;
public:
	D1() : d1(1) {}
	D1(int d) : d1(d) {}
	D1(int d, int dt) : Base(dt), d1(d) {}
};



class D2 : protected Base, protected D1
{
protected:
	int d2;
public:
	D2() : d2(1) {}
	D2(int d) : d2(d) {}
	D2(int d, int dt, int a, int b) : Base(dt), D1(a,b), d2(d) {}
};


class D3 : protected Base, protected D1
{
protected:
	int d3;
public:
	D3() : d3(1) {}
	D3(int d) : d3(d) {}
	D3(int d, int dt, int a, int b) : Base(dt), D1(a, b), d3(d) {}
};


class D23 : protected D2, protected D3
{

protected:
	double d23;
public:
	D23() : d23(1){}
	D23(int d) : d23(d){}
	D23(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, double d9) : 
		D2(d1, d2, d3, d4), 
		D3(d5, d6, d7, d8), d23(d9){}
};
// 
// V
//



class D1V : virtual protected Base
{
protected:
	int d1;
public:
	D1V() : d1(1) {}
	D1V(int d) : d1(d) {}
	D1V(int d, int dt) : Base(dt), d1(d) {}
};



class D2V : virtual protected Base, virtual protected D1V
{
protected:
	int d2;
public:
	D2V() : d2(1) {}
	D2V(int d) : d2(d) {}
	D2V(int d, int dt, int a, int b) : Base(dt), D1V(a, b), d2(d) {}
};


class D3V : virtual protected Base, virtual protected D1V
{
protected:
	int d3;
public:
	D3V() : d3(1) {}
	D3V(int d) : d3(d) {}
	D3V(int d, int dt, int a, int b) : Base(dt), D1V(a, b), d3(d) {}
};


class D23V : virtual protected D2V, virtual protected D3V
{

protected:
	double d23;
public:
	D23V() : d23(1) {}
	D23V(int d) : d23(d) {}
	D23V(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, double d9) :
		D2V(d1, d2, d3, d4),
		D3V(d5, d6, d7, d8), d23(d9) {}
};

int main()
{
	D23 obj(1, 2, 3, 4, 5, 6, 7, 8, 9.5);
	D23V objV(1, 2, 3, 4, 5, 6, 7, 8, 9.5);
	std::cout << "Size of Base: " << sizeof(Base) << " bytes" << std::endl;
	std::cout << "Size of D1: " << sizeof(D1) << " bytes" << std::endl;
	std::cout << "Size of D2: " << sizeof(D2) << " bytes" << std::endl;
	std::cout << "Size of D3: " << sizeof(D3) << " bytes" << std::endl;
	std::cout << "Size of D23: " << sizeof(D23) << " bytes" << std::endl;
	std::cout << std::endl;
	std::cout << "Size of D1V: " << sizeof(D1V) << " bytes" << std::endl;
	std::cout << "Size of D2V: " << sizeof(D2V) << " bytes" << std::endl;
	std::cout << "Size of D3V: " << sizeof(D3V) << " bytes" << std::endl;
	std::cout << "Size of D23V: " << sizeof(D23V) << " bytes" << std::endl;
	return 0;
}