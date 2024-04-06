#pragma once
#include <iostream>
using namespace std;

// Question 1

/*Write a program to ask the user to enter 10 float values in an array. Then calculate and display
the average of all the values in the array and also, the position and the value of the item in array
which is closer to the average.
*/
void W3_EX1() {
	const int SIZE = 10;
	int pos;
	float sum = 0, quantity = 0, diff = 10000000000;
	float average, number;
	float A[SIZE] = { 0 };

	cout << "\nEnter 10 float values: ";
	for (int i = 0; i < SIZE; i++) {
		cout << '\n' << i + 1 << " value: ";
		cin >> A[i];
	}
	for (int i = 0; i < SIZE; i++) {
		quantity += 1;
		sum += A[i];
	}
	average = sum / quantity;
	for (int i = 0; i < SIZE; i++) {
		if ((abs(A[i] - average)) < diff) {
			diff = abs(A[i] - average);
			number = A[i];
			pos = i;
		}
	}
	cout << "\n" << average << " is the average.";
	cout << "\nThe closest number is " << number << " at position " << pos << ".\n\n";
}

// Question 3

/*Write a program and declare two arrays A and B with 100 integers. Hence, ask the user to enter
the value of a variable n and while n is not within the range [1,100] keep asking for another value.
Then your program will prompt for n integer values for each of the two arrays. Finally, the
program will check if the two arrays have the same values at the same positions (that is if
A[i]==B[i] for 0≤i<n), and if they do, it will display “Arrays are equal”, otherwise it will display
“Array are NOT equal”.
*/
void W3_EX3() {
	const int SIZE = 100;
	int A[SIZE], B[SIZE], n = 101;
	bool flag = true;
	while ((n <= 0) or (n >= 100)) {
		cout << "\nEnter the value of n in the range [1,100]: ";
		cin >> n;
	}
	cout << "\nEnter " << n << " values for two arrays...\n";
	for (int i = 0; i < n; i++) {
		cout << "\nEnter " << i + 1 << " value for 1st array: ";
		cin >> A[i];
	}
	cout << "\n-----------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		cout << "\nEnter " << i + 1 << " value for 2nd array: ";
		cin >> B[i];
	}
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) flag = false;
	}
	if (flag) cout << "\nArrays are equal";
	else cout << "\nArrays are NOT equal";

}