#include "QuadraticEquation.hpp"

int main(void) {
	double a = 0.563726;
	double b = -3;
	double c = -1.262626;
	QuadricEquation equation(a, b, c);
	equation.PrintSolution();
	Roots s = equation.GetSolution();

}