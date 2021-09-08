#include <iostream>
using namespace std;

int main() {
	int arr[5];
	for (int i = 0; i < 5; i++)	cin >> arr[i];
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				flag = true;
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				for (int i = 0; i < 5; i++)	cout << arr[i] << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}