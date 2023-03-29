#include <iostream>

using namespace std;

#define MAX_N 1'000'000

long long arr[MAX_N + 1];
long long tree[MAX_N * 4];
long long lazy[MAX_N * 4];

long long set_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	return tree[node] = set_tree(start, mid, node * 2) + set_tree(mid + 1, end, node * 2 + 1);
}

long long get_sum(int start, int end, int node, int left, int right) {
	if (lazy[node]) {
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += ((long long)end - start + 1) * lazy[node];
		lazy[node] = 0;
	}

	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;

	return get_sum(start, mid, node * 2, left, right) + get_sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int left, int right, int value) {
	if (lazy[node]) {
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += ((long long)end - start + 1) * lazy[node];
		lazy[node] = 0;
	}

	if (start > right || end < left)	return;
	if (left <= start && end <= right) {
		tree[node] += ((long long)end - start + 1) * value;
		if (start != end) {
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	for (int n = 1; n <= N; n++)	cin >> arr[n];
	M += K;
	set_tree(1, N, 1);

	long long command, a, b, c;
	for (int m = 0; m < M; m++) {
		cin >> command;
		if (command == 1) {
			cin >> a >> b >> c;
			update(1, N, 1, a, b, c);
		}
		else {
			cin >> a >> b;
			cout << get_sum(1, N, 1, a, b) << "\n";
		}
	}
	return 0;
}