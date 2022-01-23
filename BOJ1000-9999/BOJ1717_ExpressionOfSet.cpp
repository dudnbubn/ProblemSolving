// key point : Union & Find

#include <iostream>
using namespace std;

int p[1000001];

int root(int x) {
	if (x == p[x])	return x;

	return p[x] = root(p[x]);
}

void uni(int x, int y) {
	x = root(x);
	y = root(y);

	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)	p[i] = i;

	int cmd, x, y;
	for (int i = 0; i < m; i++) {
		cin >> cmd >> x >> y;
		switch (cmd) {
		case 0:
			uni(x, y);
			break;
		case 1:
			if (root(x) == root(y))	cout << "YES\n";
			else	cout << "NO\n";
			break;
		}
	}
	return 0;
}