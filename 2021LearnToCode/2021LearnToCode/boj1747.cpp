#include "boj1747.h"



bool palindrome(int n) {
	string temp1 = to_string(n);
	string temp2 = "";

	for (int i = temp1.size() - 1; i >= 0; i--)
		temp2 += temp1[i];

	if (temp1 == temp2) return true;
	else return false;
}

bool check_prime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	else if (n % 2 == 0) return false;

	int ref = sqrt(n);
	for (int i = 3; i < ref + 1; i += 2) {
		if (n == 3) return true;
		else if (n % 3 == 0) return false;
		if (n % i == 0) return false;
	}
	return true;
}

void run1747() {
	int num = 0;
	cin >> num;


	while (1) {
		if (palindrome(num) == true && check_prime(num) == true) {
			cout << num;
			break;
		}
		num++;
	}
}