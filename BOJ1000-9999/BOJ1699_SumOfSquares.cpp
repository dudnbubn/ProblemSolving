// ��׶��� �� ������ ����(��� ���� ������ ���ƾ� 4���� �������� ���̴�.) �� ����
// 4 �� for������ 4���� ���� ���� n ������ �������� ��� ��츦 ���Ѵ�.

#include <iostream>
#include <algorithm>
using namespace std;

int cnt[100001] = { 0, };

int main() {
	int n;
	cin >> n;
	int c;
	for(int i=0;i*i<=n;i++){
		for (int j = i; i * i + j * j <= n; j++) {
			for (int k = j; i * i + j * j + k * k <= n; k++) {
				for (int l = k; i * i + j * j + k * k + l * l <= n; l++) {
					c = 4;
					if (i == 0) c--;
					if (j == 0) c--;
					if (k == 0) c--;
					if (l == 0) c--;
					if (cnt[i * i + j * j + k * k + l * l] != 0)
						cnt[i * i + j * j + k * k + l * l] = min(c, cnt[i * i + j * j + k * k + l * l]);
					else
						cnt[i * i + j * j + k * k + l * l] = c;
				}
			}
		}
	}
	cout << cnt[n];
	return 0;
}