#include <iostream>

using namespace std;

#define MAX_N 500'000

int arr[MAX_N + 1];
int tree[4 * MAX_N];
int lazy[4 * MAX_N];

int set_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	return tree[node] = set_tree(start, mid, node * 2) ^ set_tree(mid + 1, end, node * 2 + 1);
}

int get_xor(int start, int end, int node, int left, int right) {
	if (lazy[node]) {
		if ((end - start + 1) & 1)	tree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}

	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return get_xor(start, mid, node * 2, left, right) ^ get_xor(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int left, int right, int value) {
	if (lazy[node]) {
		if ((end - start + 1) & 1)	tree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}

	if (start > right || end < left)	return;
	if (left <= start && end <= right) {
		if (start != end) {
			lazy[node * 2] ^= value;
			lazy[node * 2 + 1] ^= value;
		}
		if ((end - start + 1) & 1)	tree[node] ^= value;
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);

	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N;
	for (int n = 1; n <= N; n++)	cin >> arr[n];
	set_tree(1, N, 1);

	cin >> M;

	int cmd, i, j, k;
	for (int m = 0; m < M; m++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> i >> j >> k;
			update(1, N, 1, i + 1, j + 1, k);
		}
		else {
			cin >> i >> j;
			cout << get_xor(1, N, 1, i + 1, j + 1) << "\n";
		}
	}
	return 0;
}