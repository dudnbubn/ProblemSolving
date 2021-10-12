// ���� ��ġ�� ���� ���� �� ���� �� �ִٴ� ���� ����.
// ���� ���� ��ġ�� ������ �� �ִٰ� �����Ͽ� set�� �̿��� �ߺ��� �����߾��µ�
// [1 10 10] �� ��� �ߺ��� �����ϸ� [1 10]�� �Ǿ� ���� 1�� ��������
// �ùٸ� Ǯ�̴� 1�� �� 9+9 = 18, 10�� �� 9+0=9 �� �Ǿ� 10�� �����̴�.

#include <iostream>
#include <algorithm>
using namespace std;

int arr[200010];
long long sum[200010];

int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)	sum[i] = sum[i - 1] + arr[i - 1];

	long long minimum = 200000000000, location = 0;
	long long d = 0, up, low;
	for (int i = 0; i < n; i++) {
		up = upper_bound(arr, arr + n, arr[i]) - arr;
		low = lower_bound(arr, arr + n, arr[i]) - arr;
		d = (low * arr[i] - sum[low]) + (sum[n] - sum[up]) - ((n - up) * arr[i]);

		if (minimum > d) {
			minimum = d;
			location = arr[i];
		}
	}
	cout << location;
	return 0;
}