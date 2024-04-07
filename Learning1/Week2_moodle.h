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

/*Question 2
Write a program and declare an array called “A” with 100 integers. Hence, ask the user to
enter the value of a variable n and while n is not within the range [1,100] keep asking for
another value. Then your program will prompt for n integer values and stores them in the
array. Finally, the program will check if the values in the array are sorted in ascending order
(that is if every next value is bigger than its previous one), and if they are it will display “Array
is sorted”, otherwise it will display “Array is NOT sorted”.*/
void W2_EX2() {
	const int SIZE = 100;
	int A[SIZE] = { 0 };
	int n = -1;
	bool flag = true;
	while (n < 1 or n > 100) {
		cout << "\nEnter value of n (range = [1,100]): ";
		cin >> n;
	}
	cout << "\nEnter " << n << " values...";
	for (int i = 0; i < n; i++) {
		cout << "\nEnter " << i << " value: ";
		cin >> A[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (A[i] > A[i + 1]) flag = false;
	}
	if (flag) cout << "\nArray is sorted.";
	else cout << "\nArray is NOT sorted.";
}