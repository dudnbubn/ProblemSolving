#include <iostream>
#include <algorithm>
using namespace std;

int arr[15000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	int start = 0, end = n - 1, cnt = 0, sum;
	while (start < end) {
		sum = arr[start] + arr[end];
		if (sum <= m) {
			if (sum == m)	cnt++;
			start++;
		}
		else	end--;
	}
	cout << cnt;
	return 0;
}