#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100000];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n, compare);

	int cnt = 1;
	int start = arr[0].first;
	int end = arr[0].second;
	for (int i = 1; i < n; i++) {
		if (arr[i].first >= end) {
			cnt++;
			end = arr[i].second;
		}
	}
	cout << cnt;
	return 0;
}