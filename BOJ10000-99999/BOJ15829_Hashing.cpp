#include <iostream>

using namespace std;

#define M 1234567891

int main() {
	int N;
	cin >> N;

	string input;
	cin >> input;

	long long result = 0;
	long long R = 1;
	for (int i = 0; i < N; i++) {
		result = (result + (input[i] - 'a' + 1) * R) % M;
		R = (R * 31) % M;
	}
	cout << result;
	return 0;
}