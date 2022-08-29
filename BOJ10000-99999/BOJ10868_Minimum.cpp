#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int tree[400001];

int getTree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = min(getTree(start, mid, node * 2), getTree(mid + 1, end, node * 2 + 1));
}

int getMin(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 1e9;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return min(getMin(start, mid, node * 2, left, right), getMin(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	getTree(1, N, 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << getMin(1, N, 1, a, b) << "\n";
	}
	return 0;
}