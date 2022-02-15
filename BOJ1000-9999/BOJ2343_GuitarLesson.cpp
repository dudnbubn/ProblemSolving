// key point : Binary Search

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int start = 0, end = 1000000000;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		start = (start < arr[i] ? arr[i] : start);
	}
	int cnt, temp;
	while (start <= end) {
		int mid = (start + end) / 2;
		cnt = 1;
		temp = mid;
		for (int i = 1; i <= n; i++) {
			if (temp >= arr[i]) {
				temp -= arr[i];
			}
			else {
				temp = mid - arr[i];
				cnt++;
			}
		}

		if (cnt > m)	start = mid + 1;
		else	end = mid - 1;
	}
	cout << start;
	return 0;
}