//============================================================================
// Name        : PolynomialProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
	int a0[3] = { 2, 4, 6 };
	int b0[2] = { 5, 7 };
	int c0[5] { 2, 4, 6, 0, 0 };
	int addRes0[3] = { 7, 11, 6 };
	int multRes0[4] = { 10, 34, 58, 42 };
	Polynomial a(vector<int>(begin(a0), end(a0)));
	Polynomial b(vector<int>(begin(b0), end(b0)));
	Polynomial c(vector<int>(begin(c0), end(c0)));
	Polynomial addRes(vector<int>(begin(addRes0), end(addRes0)));
	Polynomial multRes(vector<int>(begin(multRes0), end(multRes0)));
	if (a == a)
		cout << "yay == works" << endl;
	if (a == c)
		cout << "yay == still works" << endl;
	if (c == a)
		cout << "yay == stilllll works" << endl;
	if (addRes == (a + b))
		cout << "yay + works" << endl;
	if (multRes == (a * b))
		cout << "yay * works" << endl;
	return 0;
}
