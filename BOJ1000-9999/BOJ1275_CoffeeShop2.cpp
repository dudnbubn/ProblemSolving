#include <iostream>

using namespace std;

long long arr[100001];
long long tree[400000];

long long getTree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = getTree(start, mid, node * 2) + getTree(mid + 1, end, node * 2 + 1);
}

long long getSum(int start, int end, int node, int left, int right) {
	if (end < left || right < start)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long gap) {
	if (start > index || end < index)	return;

	tree[node] += gap;
	if (start == end)	return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, gap);
	update(mid + 1, end, node * 2 + 1, index, gap);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	getTree(1, N, 1);
	int x, y, a, b;
	for (int q = 0; q < Q; q++) {
		cin >> x >> y >> a >> b;
		if (x < y)	cout << getSum(1, N, 1, x, y) << "\n";
		else	cout << getSum(1, N, 1, y, x) << "\n";

		long long gap = b - arr[a];
		update(1, N, 1, a, gap);
		arr[a] = b;
	}

	return 0;
}