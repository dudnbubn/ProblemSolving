#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int cnt[10];
unordered_map<int, vector<int>> um;

void func(int N, int divisor, bool valid) {
	if (!divisor)	return;

	int quotient = N / divisor;
	for (int i = 0; i < quotient; i++) {
		if (i == 0) {
			if (valid)	cnt[i] += divisor;
			func(divisor - 1, divisor / 10, valid);
		}
		else {
			cnt[i] += divisor;
			func(divisor - 1, divisor / 10, true);
		}
	}
	
	cnt[quotient] += (N % divisor + 1);
	int remain = N % divisor;
	func(remain, divisor / 10, true);
}

int main() {
	int input;
	cin >> input;

	long long divisor = 1;
	while (divisor <= input)	divisor *= 10;
	divisor /= 10;

	if (input == divisor) {
		int temp = input;
		while (temp) {
			cnt[0]++;
			temp /= 10;
		}
		cnt[1]++;
		cnt[0]--;
		input--;
		divisor /= 10;
	}

	func(input, (int)divisor, false);

	for (int i = 0; i < 10; i++)
		cout << cnt[i] << " ";
	
	return 0;
}