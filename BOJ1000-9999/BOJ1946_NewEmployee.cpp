#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt;
pair<int, int> employee[100000];

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		cnt = n;
		for (int i = 0; i < n; i++)	
			cin >> employee[i].first >> employee[i].second;
		sort(employee, employee + n, compare);
		int minimum = employee[0].second;
		for (int i = 1; i < n; i++) {
			if (minimum < employee[i].second)
				cnt--;
			minimum = min(minimum, employee[i].second);
		}
		cout << cnt << "\n";
	}
	return 0;
}