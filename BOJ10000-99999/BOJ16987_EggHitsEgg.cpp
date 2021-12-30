#include <iostream>
#include <algorithm>
using namespace std;

int n;
int maximum = 0;

void Brute(int prev, pair<int, int> arr[]) {
	while (prev < n && arr[prev + 1].first <= 0)
		prev++;

	if (prev >= n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i].first <= 0)
				cnt++;
		}
		maximum = max(maximum, cnt);
		return;
	}

	pair<int, int> save1 = arr[prev + 1];
	pair<int, int> save2;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (arr[i].first <= 0 || i == prev + 1)	continue;
		flag = true;
		save2 = arr[i];
		arr[i].first -= arr[prev + 1].second;
		arr[prev + 1].first -= arr[i].second;
		Brute(prev + 1, arr);
		arr[prev + 1] = save1;
		arr[i] = save2;
	}
	if (!flag) {
		Brute(prev + 2, arr);
		return;
	}
}

int main() {
	pair<int, int> arr[9];
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i].first >> arr[i].second;
	
	Brute(0, arr);
	cout << maximum;
	return 0;
}