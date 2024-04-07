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
