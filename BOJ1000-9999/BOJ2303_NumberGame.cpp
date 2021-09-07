#include <iostream>
#include <algorithm>
using namespace std;

int selec(int arr[]) {
	int result = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++)
				result = max(result, (arr[i] + arr[j] + arr[k]) % 10);
		}
	}
	return result;
}

int main() {
	int n;
	int arr[5];
	cin >> n;
	int max = 0, idx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++)
			cin >> arr[j];
		int sum = selec(arr);
		if (max <= sum) {
			max = sum;
			idx = i;
		}
	}
	cout << idx;
	return 0;
}