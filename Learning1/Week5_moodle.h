#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

//GLOBAL CONSTANTS
const int L = 255; // MAX LENGTH OF A STRING
/*Question 1
Write a program to read a c-string s1 and copy it to another string s2. Display s2. Do not use
any predefine functions apart from gets_s().*/
void W5_EX1() {
	
	char s1[L], s2[L];
	cout << "\nEnter a string: ";
	gets_s(s1);
	for (int i = 0; i < L; i++)
		s2[i] = s1[i];
	cout << s2;
}
/*Question 2
Write a program to read a c-string s and display its length. Do not use any predefine functions
apart from gets_s().*/
void W5_EX2() {
	char s[L];
	int length = 0;
	cout << "Enter a string: ";
	gets_s(s);
	for (int i = 0; s[i] != '\0'; i++) {
		length += 1;
	}
	cout << "\nThe length is " << length << ".\n";
}
/*Question 3
Write a program to read a c-string s and copy its characters in reverse before its original
content i.e. if s = “student” then it will become “tnedutsstudent”. Display s. Do
not use any predefine functions apart from gets_s().*/
void W5_EX3() {
	char s[L];
	int length = 0;
	cout << "Enter a string: ";
	gets_s(s);
	for (int i = 0; s[i] != '\0'; i++) {
		length += 1;
	}

	for (int i = 0; i < length; i++) {
		s[length + i] = s[i];
	}
	length *= 2;
	s[length] = '\0';
	for (int i = 0; i < length; i++)
		s[i] = s[length - i - 1];
	cout << s;
}
/*Question 5
Write a program and declare a pointer to double, called A. By using A allocate a dynamic array
of size n, where n is previously given by the user. Hence, prompt the user to enter n double
values. Find and display the average of the values in the array, along with the biggest value.
Throughout this program use pointer notation for the array.*/
void W5_EX5() {
	double* A;
	int n;
	cout << "How many values you will enter: ";
	cin >> n;
	double sum = 0;
	double max = 0;
	A = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " value: ";
		cin >> *(A + i);
		sum += *(A + i);
		if (max < *(A + i)) max = *(A + i);
	}
	cout << "Max: " << max << '\n';
	cout << "Average: " << sum / n << '\n';
}
/*Question 8
Add the following code in your program:
*/
struct Student_ {
	string name;
	int assignment;
	int midterm;
	int final;
};
struct UniversityClass {
	int size;
	Student_* students;
};
/*Write the main program and:
a) Declare an object (variable) of the class UniversityClass, called myClass.
b) Prompt the user to enter the number of students in the class (myClass.size), and create
a dynamic array for the data member students (myClass.students) to store the
information of each student.
c) Ask the user to enter the information for all the students in the class.
d) Display the name of each student along with his/her final grade according to the following
weights:
Assignments 15%
Midterm Exam 35%
Final Exam 50%
e) Calculate and display the class’s average grade.
f) Finally, release (delete) the memory allocated for the dynamic array (myClass.students).*/
void W5_EX8() {
	UniversityClass myClass;//a)
	cout << "Enter a number of students: ";//b)
	cin >> myClass.size;
	myClass.students = new Student_[myClass.size];
	for (int i = 0; i < myClass.size; i++) { //c)
		cin.ignore(1000, '\n');
		cout << "STUDENT NUMBER " << i << '\n';
		cout << "NAME: ";
		getline(cin, myClass.students[i].name);
		cout << "ASSIGNMENT: ";
		cin >> myClass.students[i].assignment;
		cout << "MIDTERM: ";
		cin >> myClass.students[i].midterm;
		cout << "FINAL: ";
		cin >> myClass.students[i].final;
	}
	float sum = 0;
	for (int i = 0; i < myClass.size; i++) {
		float grade = myClass.students[i].assignment * 0.15 + myClass.students[i].midterm * 0.35 + myClass.students[i].final * 0.5;
		cout << myClass.students[i].name << ": " << grade << '\n';
		sum += grade;

	}
	cout << "\n\nAVERAGE: " << sum / myClass.size;

	delete myClass.students;
}