#include "QuadraticEquation.hpp"
#include <cmath>
#include <iostream>

Roots QuadricEquation::FindRoots() {
	double D = FindDiscriminant();
	Roots roots(0, 0, 0);

	//special and linear cases
	if (a == 0.0) {
		if (b == 0.0 && c == 0.0)
			return roots;
		else  if (b == 0.0)
			return roots;
		else {
			roots.count = 1;
			roots.x1 = (-c / b);
			return roots;
		}
	}

	//general case
	if (D > 0) {
		roots.count = 2;
		roots.x1 = ((-b + sqrt(D)) / (2.0 * a));
		roots.x2 = ((-b - sqrt(D)) / (2.0 * a));
		if (roots.x1 > roots.x2) {
			double temp = roots.x2;
			roots.x2 = roots.x1;
			roots.x1 = temp;
		}
		return roots;
	}
	else if (D == 0.0) {
		roots.count = 1;
		roots.x1 = ((-b) / (2.0 * a));
		return roots;
	}
	else
		return roots;
}


void QuadricEquation::PrettyPrintEquation() {
	std::cout << "Equation: ";
	if (a != 0.0) {
		if (a == 1)
			std::cout << "x^2 ";
		else if (a == -1)
			std::cout << "-x^2 ";
		else
			std::cout << a << "x^2 ";
		if (b > 0.0)
			std::cout << "+ ";
		else if (b < 0.0)
			std::cout << "- ";
	}

	if (b != 0.0) {
		if (b == 1.0 || b == -1.0) {
			if (b == -1.0 && a == 0.0)
				std::cout << "-";
			std::cout << "x ";
		}
		else {
			if (a == 0.0)
				std::cout << b << "x ";
			else
				std::cout << fabs(b) << "x ";
		}
	}

	if (c >= 0.0) {
		if (a != 0.0 || b != 0.0) {
			if (c == 0.0)
				std::cout << "= 0\n";
			else
				std::cout << "+ " << c << " = 0\n";
		}
		else
			std::cout << c << " = 0\n";
	}
	else
		std::cout << "- " << fabs(c) << " = 0\n";
}

int QuadricEquation::PrintSolution() {
	Roots roots = FindRoots();

	PrettyPrintEquation();

	if (roots.count == 2) {
		std::cout << "Roots: x1 = " << roots.x1 << "; x2 = " << roots.x2 << "\n";
		return roots.count;
	}
	else if (roots.count == 1) {
		std::cout << "Root: x = " << roots.x1 << "\n";
		return roots.count;
	}
	else {
		std::cout << "This equation has no roots\n";
		return roots.count;
	}
}