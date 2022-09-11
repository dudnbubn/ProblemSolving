#include <iostream>

using namespace std;

long long arr[1000001];
long long tree[4000001];

long long getTree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = getTree(start, mid, node * 2) + getTree(mid + 1, end, node * 2 + 1);
}

long long getSum(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	long long mid = (start + end) / 2;
	return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long gap) {
	if (index < start || index > end)	return;

	tree[node] += gap;
	if (start == end)	return;

	long long mid = (start + end) / 2;
	update(start, mid, node * 2, index, gap);
	update(mid + 1, end, node * 2 + 1, index, gap);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	getTree(1, N, 1);

	long long a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			long long gap = c - arr[b];
			arr[b] = c;
			update(1, N, 1, b, gap);
		}
		else {
			cout << getSum(1, N, 1, b, c) << "\n";
		}
	}

	return 0;
}