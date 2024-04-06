#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

//Question 1 ( bruh it's huge )

/*Write a program and do the following:
a) Declare a 2D array called “Table” with 10 rows and 10 columns of integers.
b) Build the multiplication table of all the numbers from 1 to 10 in the array as shown in
the table below:
*/

void W4_EX1() {
	//a)
	const int SIZE_ROW = 10, SIZE_COL = 10;
	int Table[SIZE_ROW][SIZE_COL];
	int sum = 0,divBy3 = 0,dig4 = 0,sum6 = 0,sumD = 0;


	//b)
	for (int i = 0; i < SIZE_ROW; i++) {
		for (int j = 0; j < SIZE_COL; j++) {
			Table[i][j] = (i+1) * (j+1);
		}
	}
	//c)
	for (int i = 0; i < SIZE_COL; i++) {
		for (int j = 0; j < SIZE_ROW; j++)
			cout << Table[i][j] << '\t';
		cout << '\n';
	}

	//d)
	for (int i = 0; i < SIZE_ROW; i++) {
		for (int j = 0; j < SIZE_COL; j++) {
			sum += Table[i][j];
		}
	}
	//e)
	cout << '\n' << sum << " is a sum of all numbers.\n"; 
	for (int i = 0; i < SIZE_ROW; i++) {
		for (int j = 0; j < SIZE_COL; j++) {
			if (Table[i][j] % 3 == 0) divBy3 += 1;
		}
	}
	cout << '\n' << divBy3 << " is an amount of numbers that are divisible by 3.\n";
	//f)
	for (int i = 0; i < SIZE_ROW; i++) {
		for (int j = 0; j < SIZE_COL; j++) {
			int num = Table[i][j];
			while (num > 0) {
				if (num % 10 == 4) dig4 += 1;
				num /= 10;
			}
		}
	}
	cout << '\n' << dig4 << " is an amount of numbers that have 4 as one of their digits.\n";
	//g)
	for (int i = 0; i < SIZE_COL; i++) {
		sum6 += Table[6][i];
	}
	cout << '\n' << sum6 << " is the sum of all number from row 6.\n";
	//h)
	for (int i = 0; i < SIZE_COL; i++) {
		int sumEach = 0;
		for (int j = 0; j < SIZE_ROW; j++) {
			sumEach += Table[j][i];
			
		}
		cout << "\nSum of all numbers from column " << i << " is: " << sumEach;
	}
	cout << '\n';
	//i)
	int row, num;
	bool flag = false;
	cout << "Enter row and number: ";
	cin >> row >> num;
	for (int i = 0; i < SIZE_COL; i++)
		if(Table[row][i] == num) flag = true;
	if (flag) cout << "\nThere is number " << num << '!';
	else cout << "\nThere is NO number " << num << '!';

	//j
	for (int i = 0; i < SIZE_COL; i++) {
		sumD += Table[i][i];
	}
	for (int i = 0; i < SIZE_COL; i++) {
		sumD += Table[SIZE_ROW - 1 - i][i];
	}
	cout << '\n' << sumD << " is sum of all the numbers in the two diagonals.\n";
}
int W4_EX1_checker()
{
	const int size = 4;
	// (a)
	int Table[10][10], i, j;
	// (b)
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			Table[i][j] = (i + 1) * (j + 1);
	// (c) table within a box using special characters
	cout << " ";
	for (i = 0; i < 10; i++)
		cout << setw(size) << i + 1;
	cout << "\n " << char(201);
	for (i = 0; i < 10 * size + 2; i++)
		cout << char(205);
	cout << char(187) << endl;
	for (i = 0; i < 10; i++)
	{
		cout << setw(3) << i + 1 << " " << char(186);
		for (j = 0; j < 10; j++)
			cout << setw(size) << Table[i][j];
		cout << " " << char(186) << endl;
	}
	cout << " " << char(200);
	for (i = 0; i < 10 * size + 2; i++)
		cout << char(205);
	cout << char(188) << endl;
	// (d)
	int sum = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			sum += Table[i][j];
	cout << endl << "The sum = " << sum << endl << endl;
	// (e)
	int count = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			if (Table[i][j] % 3 == 0) count++;
	cout << count << " numbers are divisible by 3.\n\n";
		// (f)
		count = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			bool havefour = false;
			int n = Table[i][j];
			while (n != 0)
			{
				if (n % 10 == 4) havefour = true;
				n /= 10;
			}
			if (havefour) count++;
		}
	cout << count << " numbers have 4 as one of their digits.\n\n";
	// (g)
	sum = 0;
	for (i = 0; i < 10; i++)
		sum += Table[6][i];
	cout << "The sum of row 6 (starting from 0) = " << sum << endl << endl;
	// (h)
	for (i = 0; i < 10; i++)
	{
		sum = 0;
		for (j = 0; j < 10; j++)
			sum += Table[j][i];
		cout << "The sum of col " << i << " = " << sum << endl;
	}
	cout << endl;
	// (i)
	int row, num;
	cout << "Enter a row (first row is row 0): ";
	cin >> row;
	cout << "Enter a number to search: ";
	cin >> num;
	i = 0;
	bool found = false;
	while (!found && i < 10)
		found = Table[row][i++] == num;
	cout << "Number " << num;
	if (found) cout << " exists in row " << row << endl << endl;
	else cout << " does NOT exist in row " << row << endl << endl;
	// (j)
	sum = 0;
	for (i = 0; i < 10; i++)
		sum += Table[i][i];
	cout << "Sum of right diagonal = " << sum << endl;
	sum = 0;
	for (i = 0; i < 10; i++)
		sum += Table[i][9 - i];
	cout << "Sum of left diagonal = " << sum << endl;
	return 0;
}
