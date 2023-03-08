#include <iostream>

using namespace std;

#define LENGTH 100'000

int arr[LENGTH + 1];
int tree[4 * LENGTH];
int lazy[4 * LENGTH];

int get_value(int start, int end, int node, int left, int right) {
	if (lazy[node]) {
		lazy[node] = 0;
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = (lazy[node * 2] + 1) % 2;
			lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1) % 2;
		}
	}

	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return get_value(start, mid, node * 2, left, right) + get_value(mid + 1, end, node * 2 + 1, left, right);
}

int update(int start, int end, int node, int left, int right) {
	if (lazy[node]) {
		lazy[node] = 0;
		if (start != end) {
			lazy[node * 2] = (lazy[node * 2] + 1) % 2;
			lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1) % 2;
		}
		tree[node] = (end - start + 1) - tree[node];
	}

	if (start > right || end < left)	return tree[node];
	if (left <= start && end <= right) {
		if (start != end) {
			lazy[node * 2] = (lazy[node * 2] + 1) % 2;
			lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1) % 2;
		}
		return 		tree[node] = (end - start + 1) - tree[node];
	}

	int mid = (start + end) / 2;

	return tree[node] = update(start, mid, node * 2, left, right) + update(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int O, S, T;
	for (int m = 0; m < M; m++) {
		cin >> O >> S >> T;

		if (O == 0) {
			update(1, N, 1, S, T);
		}
		else {
			cout << get_value(1, N, 1, S, T) << "\n";
		}
	}
	return 0;
}