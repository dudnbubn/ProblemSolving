// 10�� �ǹ��ϴ� ���ڸ� ������ �� ������ ��쿡�� �ٽ� 1�� ���� �ʿ䰡 �����Ƿ�
// ��͸� �ش� ���ں��� �� ���Ŀ� �ش��ϴ� ���ڵ�(10�� ��� 10 �� 50)�� �����ָ� �ð��ʰ��� �ذ��� �� �ִ�.

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