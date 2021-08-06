#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
char cmd[10];
int answer[10];
bool isUsed[10] = { 0, };
long long maximum = 0;
long long minimum = 9999999999;
void Brute(int k) {
	if (k == n + 1) {
		for (int i = 0; i < n; i++) {
			if (cmd[i] == '<') {
				if (answer[i] > answer[i + 1])	return;
			}
			else {
				if (answer[i] < answer[i + 1]) return;
			}
		}
		long long result = 0;
		for (int i = 0; i <= n; i++)
			result = ((result * 10) + answer[i]);
		maximum = max(maximum, result);
		minimum = min(minimum, result);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			answer[k] = i;
			Brute(k + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	string temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		cmd[i] = temp[0];
	}

	Brute(0);
	cout << maximum << "\n";
	cout.width(n + 1);
	cout.fill(48);
	cout << minimum;
	
	return 0;
}