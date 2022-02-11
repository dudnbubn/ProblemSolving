#include <iostream>

using namespace std;

int arr[1000001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			arr[j] += i;
		}
	}
	long long result = 0;
	for (int i = 1; i <= n; i++)
		result += arr[i];
	cout << result;
	return 0;
}