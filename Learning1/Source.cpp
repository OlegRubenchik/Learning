#include <iostream>
#include <string>
#include <stdlib.h> // for system("CLS")
#include "WEEK6_MOODLE.h"
#include "WEEK7_MOODLE.h"
using namespace std;
//RANDOM PRACTICE
// --------------
//arrays
void Arrays1d();
void Arrays2d();

//strings
void class_string();

//enums
void enums();

//structures and classes
void struct_();

//references and pointers
void references();
void references_reassigning();
void pointers();
void pointers_reassigning();
void pointer_to_array();
void pointer_to_pointer();

//functions
void pointers_and_references_in_a_functions();

//dynamic memory
 void dynamic_memory_allocation();
 void dynamic_memory_allocation_arrays();

 //namespaces
 void namespaces();

 //------------
//SOFDEV
void Lab3Testing();

//STRINGS AND POINTERS FROM MOODLE WEEK_5
void w5_EX1();
void w5_EX2();
void w5_EX3();
void w5_EX4(); 
void w5_EX5();

// Technical functions
void wholeInterface();
int printMenu();

//GLOBAL CONSTANTS
const int MAX = 2;
const int MAXLEN = 255; // For strings

int main() {
	namespaces();

	return 0;
}

// arrays
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

void dynamic_array() {
	int size = 7; 
	int* A = new int[size] {1,3};
	cout << *A;
	delete []A;
}
//enums

enum Sex { // Define our own "Data type"
	Male, Female, Mentally_Ill // Have values 0 , 1 , 2 ... n
};
void enums() {
	Sex p = Female; 
	std::cout << p << '\n'; // 1

}
//Structures and classes

struct Point { // Declaration of a structure/class

	int x; // Data member "x"
	int y; // Data member "y"
};
void struct_() {
	Point p; // Declaration of a variable for our struct/class
	p.x = 3; // Intializing Data member "x"
	p.y = 5; // Intializing Data member "y"
	std::cout << p.x << " " << p.y << '\n';
	p = { 1,3 }; // We can also intialize all data members at once like this. For n data members you need to insert n values in {} brackets.
	std::cout << p.x << " " << p.y << '\n';
}




// references and pointers
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
}
void pointers_reassigning() {
	//YOU CAN CHANGE THE ADDRESS WHERE POINTER IS POINTING TO:
	int x = 5; //A VALUE
	int* p; //A POINTER
	p = &x;
	int y = 1;
	cout << "The value (X): " << x << endl; // the VALUE
	cout << "The address of a value (&x): " << &x << endl; // the ADDRESS of a VALUE
	cout << "The pointer (p): " << p << endl; // the ADDRESS where POINTER POINTS
	cout << "The value that pointer is pointing to (*p): " << *p << endl; // the VALUE thats stores in the ADDRESS where POINTER POINTS
	cout << "Added a new variable (int y = 1;)\n";
	cout << "The address where pointer is pointing to: " << p << endl;
	p = &y; // Reassigning "p" to a NEW ADDRESS
	cout << "'p' is reassigned to a NEW ADDRESS of 'y'. (p = &y;)\n";
	cout << "Now the address where pointer is pointing to has changed: " << p << endl;


	cout << endl;
	cout << endl;
}
void pointer_to_array() {
	int ARRAY[] = { 1,3,5 };
	cout << "The ADDRESS of the first elemnt of an ARRAY: " << ARRAY << endl; // the ADDRESS of the FIRST ELEMENT in the ARRAY
	int* p;
	p = ARRAY; // copying the ADDRESS of the FIRST ELEMENT of an ARRAY to a pointer "p"
	cout << "The VALUE that STORES in the ADDRESS of (1+1) ELEMENT of an ARRAY (*(p + 1)): " << *(p + 1); 
			   // printing the VALUE that STORES in the ADDRESS of (1+1) ELEMENT of an ARRAY
}	
void pointer_to_pointer() {
	//@TODO
	cout << "Developing...";
}

void dynamic_memory_allocation(){ // dynamicly allocate an integer variable
	// TWO KEYWORDS: new AND delete
	// new - creates a variable in a HEAP. We can access the variables in a HEAP only by using pointers.
	// delete - deletes that variable from a HEAP (obviously).

	int* pointer_to_new_variable/**stores the ADDRESS*/ = new int;// returns a memory address 

	// "pointer_to_new_variable" was statically allocated at compile time
	// unnamed variable(new int) dynamically allocated at run time
	// so now we have TWO variables. One in the STACK and one in the HEAP

	*pointer_to_new_variable = 8; //A variable that stores in the HEAP was accessed by using a pointer and got initialized
	cout << *pointer_to_new_variable;
	delete pointer_to_new_variable; // Free the memory(delete) of anything that stores in the ADDRESS where this POINTER IS POINTING TO
} 
void dynamic_memory_allocation_arrays() {
	int n; // Statically allocated variable (in the STACK)
	int* array_pointer; // Also statically allocated variable (in the STACK)
	
	//Now let's DYNAMICLLY allocate n integers
	cout << "Enter the size of an array: ";
	cin >> n;

	//Creating an array of a size n using dynamic memory allocation
	array_pointer = new int[n]; // NOTE: we use (int) because we want to store integers

	//Let the user insert all numbers
	for (int i = 0; i < n; i++) {
		cout << "Enter a number at poistion " << i << ": ";
		cin >> array_pointer[i];
	}
	//Show an array

	//WE CAN USE TWO METHODS FOR ACCESSING THE ELEMENTS OF DYNAMIC ARRAYS;
	// First one. Like with a simple array:
	for (int i = 0; i < n; i++) 
		cout << array_pointer[i] << ' ';
	cout << endl;
	cout << endl;
	// Second one. Use pointer notaion. 
	// REMINDER: "array_pointer" stores the ADDRESS of the FIRST ELEMENT of an ARRAY
	for (int i = 0; i < n; i++)
		cout << *(array_pointer + i) << ' ';
	cout << endl;

	//To delete an ENTIRE ARRAY from a HEAP we need to use square brackets before the name.
	delete []array_pointer; 
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





void class_string() {
	string str = " Yo, wassup?";
	str += '!';
	cout << str + " Nigga"  << endl;
}


//namespaces
namespace MyGlobals {
	int x = 78;
	const int y = 5;
}
void namespaces() {
	//cout << x; // ERRROR
	cout << MyGlobals::x << '\n';
	cout << MyGlobals::y << '\n';
	MyGlobals::x = 3;
	cout << MyGlobals::x << '\n';
}


// sofdev
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


int printMenu() {
	int choice;
	cout << endl;
	cout << "0) Quit\n";
	cout << "1) Practice C++ topics\n";
	cout << "2) See solutions for PP1 exercises from moodle\n";
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}
int practiceMenu() {
	int choice = 0;
	cout << endl;
	cout << "0) Quit\n";
	cout << "1) Arrays1d()\n";
	cout << "2) Arrays2d()\n";
	cout << "-----------------\n";
	cout << "3) class_string()\n";
	cout << "-----------------\n";
	cout << "4) references()\n";
	cout << "5) references_reassigning() \n";
	cout << "6) pointers()\n";
	cout << "7) pointers_reassigning()\n";
	cout << "8) pointer_to_array()\n";
	cout << "9) pointer_to_pointer()\n";
	cout << "-----------------\n";
	cout << "10) pointers_and_references_in_a_functions()\n";
	cout << "-----------------\n";
	cout << "11) dynamic_memory_allocation()\n";
	cout << "12) dynamic_memory_allocation_arrays()\n";
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}
bool practiceAction(int choice) {
	switch (choice) {
	case 0: return false;
	case 1:
		system("CLS");
		Arrays1d();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 2:
		system("CLS");
		Arrays2d();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 3:
		system("CLS");
		class_string();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 4:
		system("CLS");
		references();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 5:
		system("CLS");
		references_reassigning();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 6:
		system("CLS");
		pointers();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 7:
		system("CLS");
		pointers_reassigning();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 8:
		system("CLS");
		pointer_to_array();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 9:
		system("CLS");
		pointer_to_pointer();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 10:
		system("CLS");
		pointers_and_references_in_a_functions();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 11:
		system("CLS");
		dynamic_memory_allocation();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	case 12:
		system("CLS");
		dynamic_memory_allocation_arrays();
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;
	default:
		system("CLS");
		cerr << "Are you dumb?" << endl;
		cout << endl;
		cout << endl;
		cout << "Go in the code, find that function and see how it works";
		cout << endl;
		cout << endl;
		break;


		
	}
}
void wholeInterface() {
	bool flag_0 = true;
	while (flag_0) {
		switch (printMenu()) {
		case 0: {
			flag_0 = false;
			break; }
		case 1: {
			bool flag_1 = true;
			while (flag_1) {  
				flag_1 = practiceAction(practiceMenu()); // "practiceAction" returns false if "practiceMenu" returns 0.
				if (flag_1) {
					int choice;
					cout << "Enter any number to continue: ";
					cin >> choice;
				}
				
			}
			break; }
		case 2:
			cout << "Developing..." << endl;
			break;
		default:
			cerr << "Are you dumb?" << endl;
			break;
		}
	
	}
}

// Question 5
