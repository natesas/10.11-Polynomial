/*
 * Polynomial.h
 *
 *  Created on: Apr 13, 2014
 *      Author: Student
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>

class Polynomial {
public:
	Polynomial(std::vector<int>);
	explicit Polynomial(int); // make a zero polynomial of degree n
	virtual ~Polynomial();
	Polynomial operator+(Polynomial);
	Polynomial operator-(Polynomial);
	Polynomial operator-(); // unary negation NOT subtraction :D
	Polynomial operator=(Polynomial);
	Polynomial operator*(Polynomial);
	Polynomial operator+=(Polynomial);
	Polynomial operator-=(Polynomial);
	bool operator==(Polynomial);
	Polynomial operator*=(Polynomial);
	int degree();
private:
	std::vector<int> coefficients;
};

#endif /* POLYNOMIAL_H_ */
