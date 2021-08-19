// 연산자를 조합하여 나올 수 있는 모든 경우를 탐색하여
// 각 연산자 조합에 대해 계산하여 최댓값, 최솟값을 결정한다.
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[12] = { 0, };
int answer[11] = { 0, };
int oper[4] = { 0, };
int maximum = -1000000000;
int minimum = 1000000000;

void Brute(int k) {
	if (k == n - 1) {
		int result = arr[0];
		for (int i = 0; i < n - 1; i++) {
			switch (answer[i]) {
			case 0:	result += arr[i + 1];	break;
			case 1:	result -= arr[i + 1];	break;
			case 2:	result *= arr[i + 1];	break;
			case 3:	result /= arr[i + 1];	break;
			}
		}
		maximum = max(maximum, result);
		minimum = min(minimum, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			oper[i]--;
			answer[k] = i;
			Brute(k + 1);
			oper[i]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	Brute(0);
	cout << maximum << "\n" << minimum;
	return 0;
}