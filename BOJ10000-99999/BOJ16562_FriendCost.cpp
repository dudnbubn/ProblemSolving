#include <iostream>

using namespace std;

int n, m, k;
int cost[10001];
int root[10001];
bool visited[10001];

int Find(int x) {
	if (x == root[x])	return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (cost[x] < cost[y])	root[y] = x;
	else					root[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		root[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		Union(x, y);
	}

	int r;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		r = Find(i);
		if (!visited[r]) {
			visited[r] = true;
			result += cost[r];
		}
	}
	if (result <= k)	cout << result;
	else	cout << "Oh no";
	return 0;
}