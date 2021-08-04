// algorithm �� �ִ� next_permutation �̶�� �Լ��� ���� �ٷ� �ذ�Ǵ� ��������..
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[10000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	bool flag = true;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << -1;
	else {
		next_permutation(arr, arr + n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	return 0;
}