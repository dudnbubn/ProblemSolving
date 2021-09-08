#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, pair<int, int>>> medal;

medal countries[1001];

bool compare(medal a, medal b) {
	if (a.second.first == b.second.first) {
		if (a.second.second.first == b.second.second.first) {
			return a.second.second.second > b.second.second.second;
		}
		return a.second.second.first > b.second.second.first;
	}
	return a.second.first > b.second.first;
}

int main() {
	int n, k, c, g, s, b;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> c >> g >> s >> b;
		countries[i] = { c,{g,{s,b}} };
	}
	sort(countries, countries + n, compare);
	int rank = 1, equal = 1;
	if (countries[0].first == k)	cout << rank;
	else{
		for (int i = 1; i < n; i++) {
			if (countries[i].second == countries[i - 1].second) equal++;
			else {
				rank += equal;
				equal = 1;
			}
			if (countries[i].first == k) {
				cout << rank;
				break;
			}
		}
	}
	return 0;
}