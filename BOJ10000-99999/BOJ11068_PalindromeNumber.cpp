#include <iostream>
using namespace std;

int arr[21] = { 0, };

bool palindrome(int num, int d) {	
	int div = 1, index;
	while (div <= num) div *= d;
	div /= d;
	for (index = 0; div > 0; index++, div /= d) {
		arr[index] = num / div;
		num %= div;
	}
	for (int i = 0; i < index; i++) {
		if (arr[i] != arr[index - i - 1])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testcase, num;
	cin >> testcase;
	while (testcase--) {
		cin >> num;
		bool flag = false;
		for (int i = 2; i <= 64; i++) flag = (flag || palindrome(num, i));

		if (flag)	cout << 1 << "\n";
		else	cout << 0 << "\n";
	}
	return 0;
}