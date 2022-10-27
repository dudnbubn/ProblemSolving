#include <iostream>

using namespace std;

int arr[100001];
int tree[400000];

int getTree(int start, int end, int node) {
	if (start == end)	return tree[node] = (arr[start] & 1);

	int mid = (start + end) / 2;
	return tree[node] = getTree(start, mid, node * 2) + getTree(mid + 1, end, node * 2 + 1);
}

int getOdd(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;

	return getOdd(start, mid, node * 2, left, right) + getOdd(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int change) {
	if (index < start || index > end)	return;

	if (start == end) {
		tree[node] = (change & 1);
	}
	else {
		int mid = (start + end) / 2;

		update(start, mid, node * 2, index, change);
		update(mid + 1, end, node * 2 + 1, index, change);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	getTree(1, N, 1);

	int M;
	cin >> M;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			if (arr[b] % 2 == c % 2)	continue;
			arr[b] = c;
			update(1, N, 1, b, c);
		}
		else if (a == 2) {
			cout << c - b - getOdd(1, N, 1, b, c) + 1 << "\n";
		}
		else {
			cout << getOdd(1, N, 1, b, c) << "\n";
		}
	}
	return 0;
}