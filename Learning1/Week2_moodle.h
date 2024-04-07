#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

/*Question 1
Write a program and do the following each in a separate statement:
a) Declare an array called “num” with 15 integers.
b) Initialize all the elements of the array to 0.
c) Change all the elements of the array with an ODD position to -1.
d) Ask the user to enter values only at the elements with an EVEN position.
e) Display*/
void W2_EX1() {
	int num[15] = { 0 };
	for (int i = 0; i < 15; i++) 
		if (i % 2 == 1) num[i] = -1;
	for (int i = 0; i < 15; i += 2) {
		cout << "\nEnter value at position " << i << ": ";
		cin >> num[i];
	}
	for (int i = 0; i < 15; i++) {
		cout << num[i] << setw(5);
		
	}
}