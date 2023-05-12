#include <iostream>

using namespace std;

#define MAX_N 1024

int N, M;
int arr[MAX_N + 1][MAX_N + 1];
int tree[MAX_N * 4][MAX_N * 4];
int leaf_start;

void update(int x, int y, int value) {
	int i = y + leaf_start - 1;
	int j = x + leaf_start - 1;
	tree[i][j] = value;
	while (j > 1) {
		j /= 2;
		tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1];
	}
	
	while (i > 1) {
		j = x + leaf_start - 1;

		i /= 2;
		tree[i][j] = tree[i * 2][j] + tree[i * 2 + 1][j];
		while (j > 1) {
			j /= 2;
			tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1];
		}
	}
}

int get_x(int start, int end, int xnode, int ynode, int x1, int x2) {
	if (x2 < start || end < x1)	return 0;
	if (x1 <= start && end <= x2)	return tree[ynode][xnode];

	int mid = (start + end) / 2;
	return get_x(start, mid, xnode * 2, ynode, x1, x2) + get_x(mid + 1, end, xnode * 2 + 1, ynode, x1, x2);
}


int get_y(int start, int end, int ynode, int y1, int y2, int x1, int x2) {
	if (start > y2 || end < y1)	return 0;
	if (y1 <= start && end <= y2)	return get_x(1, N, 1, ynode, x1, x2);

	int mid = (start + end) / 2;
	return get_y(start, mid, ynode * 2, y1, y2, x1, x2) + get_y(mid + 1, end, ynode * 2 + 1, y1, y2, x1, x2);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	leaf_start = 1;
	while (leaf_start < N)	leaf_start *= 2;
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			update(i, j, arr[i][j]);
		}
	}

	int cmd;
	int x, y, value;
	int x1, x2, y1, y2;
	for (int m = 0; m < M; m++) {
		cin >> cmd;
		if (cmd) {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << get_y(1, N, 1, y1, y2, x1, x2) << "\n";
		}
		else {
			cin >> x >> y >> value;
			update(x, y, value);
		}
	}
	return 0;
}