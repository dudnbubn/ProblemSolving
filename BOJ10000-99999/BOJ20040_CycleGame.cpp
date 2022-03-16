#include <iostream>

using namespace std;

int n, m;
int p[500000];

int find(int x) {
	if (x == p[x])	return x;
	return p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);

	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)	p[i] = i;

	int result = 0;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		if (find(x) == find(y)) {
			result = i;
			break;
		}
		else
			uni(x, y);
	}
	cout << result;
	return 0;
}