/*
 * Polynomial.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Student
 */

#include "Polynomial.h"
#include <algorithm>

Polynomial::Polynomial(std::vector<int> coef) {
	coefficients = coef;
}

Polynomial::Polynomial(int degree) {
	coefficients = std::vector<int>(degree);
}

Polynomial::~Polynomial() {
	// TODO Auto-generated destructor stub
}

Polynomial Polynomial::operator+(Polynomial b) {
	Polynomial ret = *this;
	for (int i = 0; i < std::max(this->degree(), b.degree()); i++) {
		if (i > this->degree()) {
			ret.coefficients.push_back(b.coefficients[i]);
		}
		ret.coefficients[i] += i < b.degree() ? b.coefficients[i] : 0;
	}
	return ret;
}

Polynomial Polynomial::operator-(Polynomial b) {
	Polynomial ret = *this;
	ret += (-b);
	return ret;
}

Polynomial Polynomial::operator *(Polynomial b) {
	Polynomial ret(degree() + b.degree() - 1);
	for (int i = 0; i < degree(); i++) {
		for (int j = 0; j < b.degree(); j++) {
			ret.coefficients[i + j] += (coefficients[i] * b.coefficients[j]);
		}
	}
	return ret;
}

Polynomial Polynomial::operator +=(Polynomial b) {
	*this = *this + b;
	return *this;
}

Polynomial Polynomial::operator -=(Polynomial b) {
	*this = *this - b;
	return *this;
}

Polynomial Polynomial::operator *=(Polynomial b) {
	*this = *this * b;
	return *this;
}

Polynomial Polynomial::operator =(Polynomial b) {
	if (this == &b)
		return *this;
	coefficients = b.coefficients;
	return *this;
}

Polynomial Polynomial::operator-() {
	Polynomial ret = *this;
	for (int i = 0; i < degree(); i++) {
		coefficients[i] *= -1;
	}
	return *this;
}

bool Polynomial::operator ==(Polynomial b) {
	int max = std::max(this->degree(), b.degree());
	for (int i = 0; i < max; i++) {
		if (!(this->coefficients[i] == b.coefficients[i]
				|| (i >= b.degree() && this->coefficients[i] == 0)
				|| (i >= this->degree() && b.coefficients[i] == 0))) {
			return false;
		}
	}
	return true;
}

int Polynomial::degree() {
	return coefficients.size();
}
