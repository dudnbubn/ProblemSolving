#include <iostream>

using namespace std;

int lefts[10];
int rights[10];

int main() {
	string left, right;
	cin >> left >> right;
	for(char c : left) {
		lefts[c - '0']++;
	}
	for(char c : right) {
		rights[c - '0']++;
	}

	long long result = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			result += ((long long)i * j * lefts[i] * rights[j]);
		}
	}
	cout << result;
}