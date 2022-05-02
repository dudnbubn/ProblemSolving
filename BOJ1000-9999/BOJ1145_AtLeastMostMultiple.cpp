#include <iostream>

using namespace std;

int arr[5];

int main() {
	int result = 100;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		result = result < arr[i] ? result : arr[i];
	}
	int cnt;
	while (true) {
		cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (result % arr[i] == 0)
				cnt++;
		}
		if (cnt > 2)	break;
		result++;
	}
	cout << result;
	return 0;
}