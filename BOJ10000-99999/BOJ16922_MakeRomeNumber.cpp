// 10을 의미하는 숫자를 더했을 때 나오는 경우에서 다시 1을 따질 필요가 없으므로
// 재귀를 해당 숫자부터 그 이후에 해당하는 숫자들(10의 경우 10 과 50)만 따져주면 시간초과를 해결할 수 있다.

#include <iostream>
using namespace std;

int n, cnt = 0;
bool make[1001] = { 0, };
int ds[4] = { 1,5,10,50 };

void Brute(int k, int sum, int index) {
	if (k == n) {
		if (!make[sum]) {
			make[sum] = true;
			cnt++;
		}
		return;
	}
	for (int i = index; i < 4; i++) {
		Brute(k + 1, sum + ds[i], i);
	}
}

int main() {
	cin >> n;
	Brute(0, 0, 0);
	cout << cnt;
	return 0;
}