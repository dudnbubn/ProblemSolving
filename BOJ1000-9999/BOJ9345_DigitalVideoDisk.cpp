#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100'000

int arr[MAX_N + 1];
int min_tree[4 * MAX_N];
int max_tree[4 * MAX_N];

void set_tree(int start, int end, int node) {
	if (start == end) {
		max_tree[node] = min_tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	set_tree(start, mid, node * 2);
	set_tree(mid + 1, end, node * 2 + 1);

	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}

int get_min(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return MAX_N;
	if (left <= start && end <= right)	return min_tree[node];

	int mid = (start + end) / 2;
	return min(get_min(start, mid, node * 2, left, right), get_min(mid + 1, end, node * 2 + 1, left, right));
}

int get_max(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return max_tree[node];

	int mid = (start + end) / 2;
	return max(get_max(start, mid, node * 2, left, right), get_max(mid + 1, end, node * 2 + 1, left, right));
}


void update(int start, int end, int node, int target, int value) {
	if (start > target || end < target)	return;

	max_tree[node] = min_tree[node] = value;
	if (start == end)	return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, target, value);
	update(mid + 1, end, node * 2 + 1, target, value);

	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}

void init(int N) {
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	set_tree(1, N, 1);
}

void swap(int N, int a, int b) {
	update(1, N, 1, a, arr[b]);
	update(1, N, 1, b, arr[a]);

	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

bool is_correct(int N, int left, int right) {
	int minimum = get_min(1, N, 1, left, right);
	int maximum = get_max(1, N, 1, left, right);

	return (minimum == left && maximum == right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;

	int N, K;
	int command, left, right;
	while (TC--) {
		cin >> N >> K;
		init(N);
		
		for (int k = 0; k < K; k++) {
			cin >> command >> left >> right;
			if (command) {
				if (is_correct(N, left + 1, right + 1))
					cout << "YES\n";
				else
					cout << "NO\n";
			}
			else {
				swap(N, left + 1, right + 1);
			}
		}
	}
	return 0;
}