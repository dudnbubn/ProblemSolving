// 같은 위치에 집이 여러 개 있을 수 있다는 점을 유의.
// 같은 집의 위치는 생략할 수 있다고 생각하여 set을 이용해 중복을 제거했었는데
// [1 10 10] 의 경우 중복을 제거하면 [1 10]이 되어 답이 1이 나오지만
// 올바른 풀이는 1일 때 9+9 = 18, 10일 때 9+0=9 가 되어 10이 정답이다.

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