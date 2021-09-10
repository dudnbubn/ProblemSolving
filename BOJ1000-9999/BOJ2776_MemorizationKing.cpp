#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1000000];

int binarySearch(int k) {
	int start = 0, end = n - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == k)	return 1;
		else if (arr[mid] < k) start = mid + 1;
		else	end = mid - 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int num;
		cin >> n;
		for (int i = 0; i < n; i++)	cin >> arr[i];
		sort(arr, arr + n);
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> num;
			cout << binarySearch(num) << "\n";
		}
	}
	return 0;
}