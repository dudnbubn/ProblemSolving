#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
pair<int, int> tree[400000];

pair<int, int> segtree(int start, int end, int node) {
	if (start == end)	return tree[node] = { arr[start], arr[start] };

	int mid = (start + end) / 2;
	pair<int, int> left = segtree(start, mid, node * 2);
	pair<int, int> right = segtree(mid + 1, end, node * 2 + 1);
	
	int minimum = left.first < right.first ? left.first : right.first;
	int maximum = left.second > right.second ? left.second : right.second;
	return tree[node] = {minimum, maximum};
}

pair<int, int> getMinMax(int start, int end, int node, int left, int right) {
	if (left > end || right < start)	return { 1e9, -1e9 };
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> l = getMinMax(start, mid, node * 2, left, right);
	pair<int, int> r = getMinMax(mid + 1, end, node * 2 + 1, left, right);
	
	int minimum = l.first < r.first ? l.first : r.first;
	int maximum = l.second > r.second ? l.second : r.second;
	return { minimum, maximum };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	segtree(1, N, 1);
	int a, b;
	pair<int, int> result;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		result = getMinMax(1, N, 1, a, b);
		cout << result.first << " " << result.second << "\n";
	}
	return 0;
}