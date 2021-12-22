#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, pair<int, int>> m;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first == b.second.first)
		return a.second.second < b.second.second;
	return a.second.first > b.second.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c, x;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (m.find(x) == m.end())
			m.insert({ x, {1, i} });
		else
			m[x].first++;
	}
	vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second.first; j++) {
			cout << v[i].first << " ";
		}
	}
	return 0;
}