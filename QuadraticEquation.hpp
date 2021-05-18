#pragma once
#include <string>

using namespace std;

class Roots {
public:
	int count;
	double x1;
	double x2;

	explicit Roots(int _count, double _x1, double _x2) : count(_count), x1(_x1), x2(_x2) {};

	friend bool operator==(const Roots& x, const Roots& y) {
		return x.count == y.count && x.x1 == y.x1 && x.x2 == y.x2;
	}

	~Roots() {};
};

class QuadricEquation {
public:
	double a;
	double b;
	double c;

	explicit QuadricEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};

	Roots GetSolution() { return FindRoots(); };
	int PrintSolution();

	friend bool operator==(const QuadricEquation& x, const QuadricEquation& y) {
		return x.a == y.a && x.b == y.b && x.c == y.c;
	}

	~QuadricEquation() {};
private:
	inline double FindDiscriminant() {
		return (a * b - 4.0 * a * c);
	}
	Roots FindRoots();
	void PrettyPrintEquation();
};
