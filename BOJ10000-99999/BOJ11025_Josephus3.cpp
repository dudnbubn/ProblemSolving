#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int result = 0;
	for (int i = 1; i <= N; i++) 
		result = (result + K) % i;

	cout << result + 1;
	return 0;
}