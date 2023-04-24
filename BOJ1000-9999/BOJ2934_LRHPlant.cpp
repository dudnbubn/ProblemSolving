#include <iostream>

using namespace std;

#define MAX_N 100'000

int tree[MAX_N * 4];
int lazy[MAX_N * 4];

int get_value(int start, int end, int node, int index) {
	if (lazy[node]) {
		tree[node] += lazy[node];

		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (start > index || index > end)	return 0;
	if (start == end && end == index) {
		int result = tree[node];
		
		tree[node] = 0;
		return result;
	}

	int mid = (start + end) / 2;
	return get_value(start, mid, node * 2, index) + get_value(mid + 1, end, node * 2 + 1, index);
}

void update(int start, int end, int node, int left, int right) {
	if (lazy[node]) {
		tree[node] += lazy[node];

		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (start > right || end < left)	return;
	if (left <= start && end <= right) {
		lazy[node]++;
		return;
	}
	
	int mid = (start + end) / 2;
	
	update(start, mid, node * 2, left, right);
	update(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int a, b;

	int result;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		result = get_value(1, MAX_N, 1, a) + get_value(1, MAX_N, 1, b);
		cout << result << "\n";

		if (b - a > 1)	update(1, MAX_N, 1, a + 1, b - 1);
	}
}