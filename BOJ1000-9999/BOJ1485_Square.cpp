#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

set<long long> dist;
pair<long long, long long> arr[4];

int main() {
	int t;
	cin >> t;
	long long d;
	while (t--) {
		dist.clear();
		for (int i = 0; i < 4; i++)	cin >> arr[i].first >> arr[i].second;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j)	continue;
				d = (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
				cout << "i : " << i << ", j : " << j << ", d : " << d << "\n";
				dist.insert(d);
			}
		}
		if (dist.size() == 2)	cout << 1 << "\n";
		else	cout << 0 << "\n";
	}
	return 0;
}