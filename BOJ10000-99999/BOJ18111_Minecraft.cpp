#include <iostream>
#include <algorithm>
using namespace std;

int arr[250010];
int sum[250010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, b, height = 0, len = 0;
	cin >> n >> m >> b;
	len = n * m;
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
		height = max(height, arr[i]);
	}
	sort(arr, arr + len);
	sum[0] = 0;
	for (int i = 1; i <= len; i++) 
		sum[i] = sum[i - 1] + arr[i - 1];

	int up, low, add, nece;
	int t = 2000000000, h, calc;
	for (int i = height; i >= 0; i--) {
		up = (upper_bound(arr, arr + len, i) - arr);
		low = (lower_bound(arr, arr + len, i) - arr);
		
		nece = low * i - sum[low];
		add = (sum[len] - sum[up]) - ((len - up) * i);
		
		if (b + add < nece)	continue;
		
		calc = add * 2 + nece;
		if (t > calc) {
			t = calc;
			h = i;
		}
		
	}
	cout << t << " " << h;
	return 0;
}