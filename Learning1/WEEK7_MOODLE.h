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
