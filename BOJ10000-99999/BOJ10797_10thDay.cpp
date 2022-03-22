#include <iostream>

using namespace std;

int main() {
	int n, num;
	int result = 0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		if (num == n)
			result++;
	}
	cout << result;
	return 0;
}