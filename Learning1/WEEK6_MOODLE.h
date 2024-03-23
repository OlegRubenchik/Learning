#pragma once
#include <iostream>
using namespace std;
void test_W6() {
	std::cout << "Working!";
}

//Question 1
/**
* a) Write a void function, called readArray, which takes as parameters a 1D-array of
integers A and an integer n, and reads n integer values and stores them in the array.
*/
void readArray(int A[],const int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "Enter a value: ";
		std::cin >> A[i];
	}

}
/**
* b) Write a function, called sum, which takes as parameters a 1D-array of integers A and an
integer n and returns the sum of the values in the array from positions 0 to n-1.
*/
int sum(int A[],int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += A[i];
	return sum;
}
/**
* c) Write a function, called equal, which takes two 1D-arrays A and B, an integer n and
returns true if the two arrays are equal and false otherwise. Two arrays are equal if they
have the same values at each position from 0 to n-1, i.e if A[i]==B[i] from 0≤in.
*/
bool equal(int A[], int B[], int n) {
	bool flag = true;
	for (int i = 0; i < n; i++)
		if (A[i] != B[i]) flag = false;
	return flag;
}
/**
* Write the function main() and declare a 105 2D-array of integers called nums. Initialize
the array with the following values:
Row 0, 2, 5 : { 1, 2, 3, 4, 5 }
Row 1, 6 : { 3, 4, 5, 6, 7 }
Row 3, 7, 8 : { 5, 6, 7, 8, 9 }
Row 4 : { 2, 3, 4, 5, 6 }

Hence, by using the functions you wrote above write the code to do the following:
i) Read values for row 9.
ii) For every row in nums, display the row number along with the sum of its values.
iii) For each row, display the rows with a higher index that are equal, i.e.
Row 0 is the same as row 2
Row 0 is the same as row 5
Row 1 is the same as row 6
Row 2 is the same as row 5
Row 3 is the same as row 7
Row 3 is the same as row 8
*/
void W6_EX1() {
	const int MAXROW = 10, MAXCOL = 5;
	int nums[MAXROW][MAXCOL] = {
								 { 1,2,3,4,5 }, // 0
								{ 3,4,5,6,7 }, // 1
								{ 1,2,3,4,5 }, // 2
								{ 5,6,7,8,9 }, // 3
								{ 2,3,4,5,6 }, // 4
								{ 1,2,3,4,5 }, // 5
								{ 3,4,5,6,7 }, // 6
								{ 5,6,7,8,9 }, // 7
								{ 5,6,7,8,9 } // 8
								};
	//i
	readArray(nums[9], MAXCOL);
	std::cout << '\n';
	//ii
	for (int i = 0; i < MAXROW;i++) {
		std::cout  << "Sum of row " << i << ": " << sum(nums[i], MAXCOL) << '\n';
	}
	std::cout << '\n';
	//iii
	for (int i = 0; i < MAXROW; i++) {
		for (int j = i + 1; j < MAXROW; j++) {
			if (equal(nums[i], nums[j], MAXCOL))
				std::cout << "Row " << i << " is the same as row " << j << '\n';

		}
	}
}

//Question 2
/**
* Write a program and declare an enumerated type called DAY with the following values: Mon,
Tue, Wed, Thu, Fri, Sat, Sun. Hence,
*/
enum DAY { Mon, Tue, Wed, Thu, Fri, Sat, Sun };
/**
a) Write a void function called display that takes a DAY and displays it. If it is a Mon display
“Monday”, if it is a Tue display “Tuesday”, etc.*/
void display(DAY day) {
	switch (day) {
	case Mon:
		std::cout << "Monday" << '\n';
		break;
	case Tue:
		std::cout << "Tuesday" << '\n';
		break;
	case Wed:
		std::cout << "Wednessday" << '\n';
		break;
	case Thu:
		std::cout << "Thursday" << '\n';
		break;
	case Fri:
		std::cout << "Friday" << '\n';
		break;
	case Sat:
		std::cout << "Saturday" << '\n';
		break;
	case Sun:
		std::cout << "Sunday" << '\n';
		break;
	}
}
/**
* b) Write a void function called yesterday, that takes a reference formal parameter d of
type DAY, and change it to the day before.
*/
void yesterday(DAY &d) {
	d = DAY(((d - 1) + 7) % 7);
}
/**
* c) Write a function called tomorrow that takes a value formal parameter d of type DAY, and
returns the day after d.
*/
DAY tomorrow(DAY d) {
	return DAY((d + 1) % 7);
}
/**
* d) Write a function called lapsed which takes a DAY d (by value) and an integer n and
returns the DAY in n days from d. Note that n may be positive or negative and incorporate
the functions tomorrow and yesterday you wrote in (a) and (b) into your coding. For
example, lapsed(Fri,13) will return Thu since 13 days from a Friday is a “Thursday”.
*/
DAY lapsed(DAY d, int n) {
	n %= 7;
	for (int i = 0; i < abs(n); i++) {
		if (n > 0) d = tomorrow(d);
		else yesterday(d);
	}
	return d;

}
/**
* e) Write a function called weekend that takes a DAY and return true if it is a Sat or a Sun,
and false otherwise.
*/

/**bool weekend(DAY d) {
	switch (d) {
	case Mon:
	case Tue:
	case Wed:
	case Thu:
	case Fri:
		return false;
	case Sat:
	case Sun:
		return true;
	}
*/
bool weekend(DAY d) {
	if (d == Sat or d == Sun)
		return true;
	else return false;
}
/**
* f) Write the main program and prompt the user to enter the day today as an integer (0 for
Mon, 1 for Tue, etc.), and display the days before and after today. Hence, use the lapsed
function to display what day it will be every 100 days for the next 2,000 days.
*/
void W6_EX2() {
	DAY d,yesterday_d;
	int int_d;

	std::cout << "Enter a todays day in a integer form: ";
	std::cin >> int_d;
	d = DAY(int_d);
	yesterday_d = DAY(int_d);
	yesterday(yesterday_d);
	std::cout << "YESTERDAY: "; display(yesterday_d);
	std::cout << "TOMORROW: ";  display(tomorrow(d));
	for (int i = 100; i <= 2000; i += 100) {
		std::cout << "In " << i << " days it will be: "; display(lapsed(d, i));

	}
}
// Question 3
//Write a program and add the following declarations:
class birthdayRec {
public:
	int day, month;
};
typedef char str[100];
class contactRec {
public:
	str name, telephone;
	birthdayRec birthday;
};
/**
* Hence, write the following functions:

a) A void function readContact that prompts the user to enter the name, telephone
number and birthday (day/month) of a contact, and returns it through a reference formal
parameter.
*/
void readContact(contactRec& contact) {
	std::cout << "Enter your name: ";
	gets_s(contact.name);
	std::cout << "Enter your telephone number: ";
	gets_s(contact.telephone);
	std::cout << "Enter your birthday: '\n";
	std::cout << "Day: ";
	std::cin >> contact.birthday.day;
	std::cout << "Month: ";
	std::cin >> contact.birthday.month;
}
/**
* b) A void function deleteContact that takes an array of contactRec, an integer n
(by reference) denoting the actual number of contacts stored in the array, and a name of
type str which is the name of the contact to be found (you may write a function to search
and return the position of the contact in the array) and removed from the array. If the
contact does not exist display an appropriate message.
*/
int search(contactRec contacts[], int n, str contactName) {
	for (int i = 0; i < n; i++) {
		if (!strcmp(contacts[i].name,contactName)) return i;
	}
	return -1;

}


void deleteContact(contactRec contacts[], int &n, str contactName) {
	int position = search(contacts, n, contactName);
	if (position < 0) std::cout << "Contact not found.\n";
	else {
		n--;
		for (int i = position; i < n; i++) {
			strcpy_s(contacts[i].name, contacts[i + 1].name);
			strcpy_s(contacts[i].telephone, contacts[i + 1].telephone);
			contacts[i].birthday.day = contacts[i + 1].birthday.day;
			contacts[i].birthday.month = contacts[i + 1].birthday.month;
		}
		std::cout << contactName << " was deleted.\n";
	}
}

/**
* c) A void function displayContacts that will take an array of contactRec, an
integer n denoting the actual number of contacts stored in the array, and display the
name, birthday and telephone number of each contact in a separate line.

*/
void displayContacts(contactRec contacts[],int n) {
	for (int i = 0; i < n; i++) {
		std::cout << contacts[i].name << ' ' << contacts[i].telephone << ' ' << contacts[i].birthday.day << ' ' << contacts[i].birthday.month << '\n';
	}

}
/*
* d) Write the function main() and declare an array of 100 contactRec, called friends,
and an integer called size to denote the actual size of contacts in the array. Hence display
the menu shown below, and make your program work accordingly.
*/
void W6_EX3() {
	const int MAX = 100;
	contactRec friends[MAX];
	int reply, size = 0;
	str name;
	char c;
	do
	{
		do {
			cout << "Enter 1 to add a contact\n";
			cout << " 2 to delete a contact\n";
			cout << " 3 to display all contacts\n";
			cout << " 4 to exit\n";
			cout << " ==> ";
			cin >> reply;
			cout << endl;
		} while (reply < 1 || reply > 4);
		while (c = getchar(), c != '\n');
		switch (reply)
		{
		case 1: if (size < MAX) readContact(friends[size++]);
			  else cout << "Memory is full\n";
			break;
		case 2: cout << "Enter name to delete: ";
			gets_s(name);
			deleteContact(friends, size, name);
			break;
		case 3: displayContacts(friends, size);
			break;
		}
		cout << endl;
	} while (reply != 4);
}
