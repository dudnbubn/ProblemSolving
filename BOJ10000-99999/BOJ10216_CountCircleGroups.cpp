// key point : Union & Find

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int p[3000];
pair<pair<int, int>, int> info[3000];

int root(int x) {
	if (p[x] == x)
		return x;
	return root(p[x]);
}

void uni(int x, int y) {
	x = root(x);
	y = root(y);

	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			p[i] = i;
			cin >> info[i].first.first >> info[i].first.second >> info[i].second;
		}

		int x1, x2, y1, y2, r1, r2;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				x1 = info[i].first.first;
				y1 = info[i].first.second;
				r1 = info[i].second;
				x2 = info[j].first.first;
				y2 = info[j].first.second;
				r2 = info[j].second;
				double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
				
				if (d <= (r1 + r2)) {
					uni(i, j);
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] == i)	cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}