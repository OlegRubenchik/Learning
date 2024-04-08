#pragma once
#include <iostream>
using namespace std;
const int STRSIZE = 256;
//Question 1
//Part A
bool isPalindrome(int n) {
	int rev = 0, temp = n;
	while (temp != 0) {
		rev = 10 * rev + temp % 10;
		temp /= 10;
	}
	return n == rev;
}
//Part B
bool isPalindrome(char s[]) {
	int size;
	for (size = 0;s[size] != '\0';size++);
	for (int i = 0;i < size;i++) {
		if (!(toupper(s[i]) >= 'A' and toupper(s[i]) <= 'Z')) {
			for (int j = i;j < size;j++) {
				s[j] = s[j + 1];
			}
			size--;
			i--;
		}

	}
	for (int i = 0;i < size/2;i++) {
		if (toupper(s[i]) != toupper(s[size - 1 - i]))
			return false;
	return true;
	}

}
void W7_EX1() {
	char phrase[STRSIZE];
	cout << "Enter a phrase: ";
	gets_s(phrase);

	cout << phrase;
	if (isPalindrome(phrase))
		cout << " is a palindrome\n";
	else
		cout << " is NOT a palindrome\n";
}
// Question 2
void Mirror(char s[]) {
	int size = 0;
	for (;s[size] != '\0';size++);

	for (int i = 0;i < size;i++)
		s[2 * size - 1 - i] = s[i];
	s[2 * size] = '\0';
}
bool  Divide(char* s) {
	int size = 0;
	for (;s[size] != '\0';size++);
	if (size / 2 - 1 > 0) {
		s[size / 2 - 1] = '\0';
		return true;
	}
	else
		return false;
}
void W7_EX2(){
	char word[256] = "Hello";
	int count = 0;
	do {
		for (int i = 0; i < count;i++) cout << ' ';
		count++;
		Mirror(word);
		cout << word << '\n';
	} while (Divide(word));
}
/*Question 3
Write a function called “addAfter” that takes as parameters a c-string str and two characters
ch1 and ch2 and adds after every occurrence of character ch1 in the string str the character
ch2. The function should return the number of times ch1 was found. NOTE that if the two
characters ch1 and ch2 are the same, then the function will do nothing and return the value -
1. You may not assume the existence of any predefined string functions.
*/
int addAfter(char str[], char ch1, char ch2) {
	int size;
	int mainCounter = 0;

	for (size = 0; str[size] != '\0'; size++);
	for (int i = 0; i < size; i++) {
		if (str[i] == ch1) {
			mainCounter++;
			int count = 0;
			for (int j = size; j > i; j--) {
				str[j + 1] = str[j];
				count++;
			}
			str[i + count + 2] = '\0';
			str[i + 1] = ch2;
			
		}
	}
	return mainCounter;
}
int addAfterBySAVVA(char str[], char ch1, char ch2)
{
	int pos = 0, size, count = 0;
	for (size = 0; str[size] != '\0'; size++);
	while (str[pos] != '\0')
	{
		if (str[pos] == ch1)
		{
			count++;
			pos++;
			size++;
			for (int i = size; i > pos; i--)
				str[i] = str[i - 1];
			str[pos] = ch2;
		}
		pos++;
	}
	return count;
}
void W7_EX3() {
	char str[STRSIZE],ch1,ch2;
	int result;
	cout << "\nEnter your phrase: ";
	gets_s(str);
	cout << "\nEnter character to find: ";
	cin >> ch1;
	cout << "\nEnter character to add: ";
	cin >> ch2;
	result = addAfterBySAVVA(str, ch1, ch2);
	cout << "\nCharacter " << ch1 << " was found " << result << " times.";
	cout << "\n\n" << str;
}
