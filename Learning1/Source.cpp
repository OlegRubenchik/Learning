#include <iostream>
#include <string>
using namespace std;
//RANDOM PRACTICE
// --------------
//arrays
void Arrays1d();
void Arrays2d();
void dynamic_array();
void pointer_to_array();

//strings
void class_string();

//references and pointers
void pointers();
void references();
void references_reassigning();
void pointers_and_references_in_a_functions();
void pointers_memory_allocation();

//SOFDEV
void Lab3Testing();

//STRINGS AND POINTERS FROM MOODLE WEEK_5
void w5_EX1();
void w5_EX2();
void w5_EX3();
void w5_EX4();
void w5_EX5();

//GLOBAL CONSTANTS
const int MAX = 2;
const int MAXLEN = 255; // For strings

int main() {
	pointer_to_array();

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
void pointer_to_array() {
	int ARRAY[] = { 1,3,5 };
	cout << ARRAY; // the ADDRESS of the FIRST ELEMENT in the ARRAY
	int* p;
	p = ARRAY; // copying that ADDRESS to a pointer "p"
	cout << *(p + 1); // printing the VALUE that STORES in the ADDRESS of (1+1) ELEMENT of an ARRAY
	
	
	cout << p[2] << endl << *p;
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
void class_string() {
	string str = " Yo, wassup?";
	str += '!';
	cout << str + " Nigga"  << endl;
}
void dynamic_array() {
	int size = 7;
	int* A = new int[size] {1,3};
	cout << *A;
	delete []A;
}
void references() {
	int x = 5;
	int& rX = x;
	cout << "VALUE(X): " << x << '\n';
	cout << "&rX:" << &rX << '\n';
	cout << "rX:" << rX << '\n';
}
void references_reassigning() { //YOU CANNOT REASSIGN REFERENCES. Here's an example:
	int a = 10; // A value 
	int& reference = a; /**"&reference" is copying an ADDRESS of VALUE "a".
							"reference" is a VALUE stored in the ADDRESS "&reference".
							*/ 
	int b = 100; // Another value
	reference = b; // The VALUE stored in the ADDRESS "&reference" got changed to a same value as b.
	cout << a; // 100

}
//BUT YOU CAN REASSIGN POINTERS
void pointers() {
	int x = 5; //A VALUE
	int* p = &x; //A POINTER
	cout << "The value (X): " << x << endl; // the VALUE
	cout << "The address of a value (&x): " << &x << endl; // the ADDRESS of a VALUE
	cout << "The pointer (p): " << p << endl; // the ADDRESS where POINTER POINTS
	cout << "The value that pointer is pointing to (*p): " << *p << endl; // the VALUE thats stores in the ADDRESS where POINTER POINTS
	cout << endl << "--------------------------------------------------" << endl;
	//YOU CAN CHANGE A VALUE STORED IN THE ADDRESS WHERE POINTER POINTS:
	*p = 10;
	cout << "Changes has been made. (*p = 10;)\n";
	cout << "Now the value (X) is: " << x << endl; // Now X == 10
	cout << endl << "--------------------------------------------------" << endl;
	//YOU CAN CHANGE THE ADDRESS WHERE POINTER IS POINTING TO:
	int y = 1;
	cout << "Added a new variable (int y = 1;)\n";
	cout << "The address where pointer is pointing to: " << p << endl;
	p = &y; // Reassigning "p" to a NEW ADDRESS
	cout << "'p' is reassigned to a NEW ADDRESS of 'y'. (p = &y;)\n";
	cout << "Now the address where pointer is pointing to has changed: " << p << endl;


	cout << endl;
	cout << endl;
}
void pointers_memory_allocation(){

}

//Functions for "pointers_and_references"
	void changeToValue_Nothing(int variable, int value) { //passed by value
		variable = value;
	}
	void changeToValue_WithReference(int& variable, int value) { //passed by reference
		variable = value;
	}
	void changeToValue_WithPointer(int* variable, int value) { //passed by pointer
		*variable = value;
	}
void pointers_and_references_in_a_functions() {
	int x = 5; //A value x that equals 5
	int* pX/**A pointer TO an ADDRESS*/ = &x/**The ADDRESS of a VALUE*/;

	changeToValue_Nothing(x, 10); // A function copying the VALUE of x and changes it inside a function
	cout << x << endl; // Still X = 5

	changeToValue_WithReference(x, 10); /**A function copying the ADDRESS of x and changes x by accessig htat ADDRESS.
										So X will be changed in it's own memory address(GLOBALLY).*/ 
	cout << x << endl; // Now X = 10

	changeToValue_WithPointer(&x, 15); // A function is copying the ADDRESS of x and changes A VALUE STORED IN THAT ADDRESS.
	cout << x << endl; // Now X = 15
}



//Strings exercises from Moodle

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

//Pointers exercises

/**
* Write a program and declare a pointer to double, called A. By using A allocate a dynamic array
of size n, where n is previously given by the user. Hence, prompt the user to enter n double
values. Find and display the average of the values in the array, along with the biggest value.
Throughout this program use pointer notation for the array.
*/
void w5_EX5() {
	int size;
	double *A, average = 0, max = 0;
	cout << "Enter size: ";
	cin >> size;
	
	A = new double[size];
	cout << "Enter " << size << " values: \n";
	for (int i = 0; i < size; i++) {
		double value;
		cout << i << ": ";
		cin >> value;
		*(A + i) = value;
	}
	/**for (int i = 0; i < size; i++) {
		cout << *(A + i) << " ";
	}*/
	for (int i = 0; i < size; i++) {
		double n = *(A + i);
		average += n;
		if (max < n) max = n;
	}
	average /= size;
	cout << "Average: " << average << '\n';
	cout << "Max: " << max << '\n';
	delete[]A;
}

