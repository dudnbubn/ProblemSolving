// ó�� Brute �Լ��� ���� ���� �� sum�� 0���� �������� �� �̹Ƿ� s�� ���Ƶ� ��������� �ʾƾ��Ѵ�.
// �׷��� sum �Ķ���Ϳ� ���� ū 100���� ������ �ǰ��� �ϰ� �־����� sum �� 100���� ���̽����� Ʋ�����ȴ�.
// ���������� |S| <= 1000000 �̶�� �־��� �ִµ� �� �׷�����..

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