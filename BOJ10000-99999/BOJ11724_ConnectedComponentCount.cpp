#include <iostream>
using namespace std;

int n, m;
int root[1001];

int find(int x) {
	if (root[x] == x)
		return x;
	else
		return find(root[x]);
}

void unionTo(int x, int y) {
	x = find(x);
	y = find(y);

	root[y] = x;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		root[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		unionTo(x, y);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i == root[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}