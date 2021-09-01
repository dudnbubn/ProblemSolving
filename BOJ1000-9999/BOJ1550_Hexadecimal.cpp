#include <iostream>
using namespace std;

int main() {
	string hex;
	int answer = 0;
	cin >> hex;
	for (int i = hex.size() - 1, d = 1; i >= 0; i--, d *= 16) {
		int dec = (hex[i] >= 'A') ? hex[i] - 'A' + 10 : hex[i] - '0';
		answer += dec * d;
	}
	cout << answer;
	return 0;
}