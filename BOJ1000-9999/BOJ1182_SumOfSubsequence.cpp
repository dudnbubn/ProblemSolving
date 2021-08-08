// 처음 Brute 함수를 실행 했을 때 sum은 0개를 선택했을 때 이므로 s와 같아도 고려해주지 않아야한다.
// 그래서 sum 파라미터에 대충 큰 100만을 넣으면 되겠지 하고 넣었더니 sum 이 100만인 케이스에서 틀려버렸다.
// 문제에서도 |S| <= 1000000 이라고 주어져 있는데 왜 그랬을까..

#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int arr[21];
bool isUsed[21] = { 0, };
int cnt = 0;

void Brute(int k,int prev, int sum) {
	if (sum == s) {
		cnt++;
	}
	if (k == 0)
		sum = 0;
	if (k == n)
		return;

	for (int i = prev + 1; i < n; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			Brute(k + 1, i, sum + arr[i]);
			isUsed[i] = false;
		}
	}
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	Brute(0, -1, 100000000);
	cout << cnt;
	return 0;
}