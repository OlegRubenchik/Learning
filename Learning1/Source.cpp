#include <iostream>
#include <string>
using namespace std;
//RANDOM PRACTICE
void Arrays1d();
void Arrays2d();
void pointers1();
void class_string();

//SOFDEV
void Lab3Testing();

//STRINGS FROM MOODLE WEEK_5
void w5_EX1();
void w5_EX2();
void w5_EX3();
void w5_EX4();

//GLOBAL CONSTANTS
const int MAX = 2;
const int MAXLEN = 255; // For strings

int main() {
	w5_EX4();

	return 0;
}


void Arrays1d() {
	int A[MAX],
		B[MAX] = { 0 };
	int sum = 0,size = 0;


	for (int i = 0; i < MAX; i++) {
		cout << "Go: ";
		cin >> A[i];
	}
	for (int i = 0; i < MAX; i++) {
		cout << A[i] << endl;
	}
	for (int i = 0; i < MAX; i++) {
		B[MAX - 1 - i] = A[i];
	}
	cout << "----------------" << endl;
	for (int i = 0; i < MAX; i++) {
		cout << B[i] << endl;
	}
	cout << "----------------" << endl;
	for (int i = 0; i < MAX; i++) {
		sum += A[i];
	}
	cout << "Sum is: " << sum << endl;
	size = sizeof(A)/sizeof(int);
	cout << "Size is: " << size << endl;
	cout << "----------------" << endl;
	for (auto n : A)
		cout << n + 1 << endl;

}
void Arrays2d() {
	int A[MAX][MAX] = {0};
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << "Initialize: ";
			cin >>  A[i][j];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) 
				cout << A[i][j]<< ' ';	
		cout << endl;
	}
}
void Lab3Testing() {
	int total[10];
	const int SIZE = 10;
	for (int i = 0; i < SIZE; i++) {
		total[i] = i;
	}
	for (int i = 0; i < SIZE; i++) {
		cout << total[i] << '\n';
	}
}
void pointers1() {
	int* ptr = new int(10);
	// printing value and address
	cout << "Address: " << ptr << endl;
	cout << "Value: " << *ptr << endl; 
}
void class_string() {
	string str = " Yo, wassup?";
	str += '!';
	cout << str + " Nigga"  << endl;
}
//Strings exercises fro Moodle

// Write a program to read a c-string s1 and copy it to another string s2. 
// Display s2. Do not use any predefine functions apart from gets_s().
void w5_EX1() {
	char s1[MAXLEN], s2[MAXLEN];
	cout << "Enter: ";
	gets_s(s1);
	for (int i = 0; i < MAXLEN; i++) {
		s2[i] = s1[i];
	}
	cout << s2;
}

//Write a program to read a c-string s and display its length. Do not use any predefine functions apart from gets_s().
void w5_EX2() {
	char s[MAXLEN];
	int length = 0, i = 0;
	cout << "Enter: ";
	gets_s(s);
	
	while (s[i] != '\0') {
		length++;
		i++;
	}
	cout << length;
}

/** Write a program to read a c-string s and copy its characters in reverse before its original
content i.e. if s = “student” then it will become “tnedutsstudent”. Display s. Do
not use any predefine functions apart from gets_s().
*/

void w5_EX3() {
	char s[MAXLEN];
	int size = 0,i = 0,j=0;
	cout << "Enter: ";
	gets_s(s);
	while (s[i] != '\0') {
		size++;
		i++;
	}
	for (int i = 0; i < size; i++) {
		s[size + i] = s[i];
	}
	size *= 2;
	s[size] = '\0';
	for (int i = 0; i < size / 2; i++) {
		s[i] = s[size - i - 1];
	}
	cout << s;
}

/** Write a program to read in characters one at a time from the keyboard and to count the
number of characters. Additionally, for alphabetical characters, the program should keep a
count (26 counts). When the user enters a full stop the program should stop, display the nonzero character counts four per line along with the corresponding character, then the overall
character and exit.
*/
void w5_EX4() {
	char c;
	int count[26] = { 0 }, total = 0, quantity = 0;
	cout << "Enter: \n";
	while (c = cin.get(), c != '.') {
		c = tolower(c);
		if (c >= 'a' and c <= 'z') count[c - 'a']++; 
		total++;
	}
	cout << endl;
	for (int i = 0; i < 26; i++) {
		if (count[i] != 0) {
			cout << char('a' + i) << " = " << count[i] << " ";
			quantity++;
		}
		if (quantity == 4) {
			cout << endl;
			quantity = 0;
		}
	}
	cout << endl << endl;
	cout << "In total: " << total << '\n';
}

