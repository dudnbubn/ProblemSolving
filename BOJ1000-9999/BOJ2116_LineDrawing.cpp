#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

pair<int, int> v[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v[i] = { start,end };
	}
	sort(v, v + n, compare);

	int len = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first <= v[i - 1].second) {
			v[i].first = v[i - 1].first;
			if (v[i].second < v[i - 1].second)
				v[i].second = v[i - 1].second;
		}
		else {
			len += (v[i - 1].second - v[i - 1].first);
		}
	}
	len += (v[n - 1].second - v[n - 1].first);
	cout << len;
	return 0;
}