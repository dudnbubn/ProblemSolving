#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100'000

int arr[MAX_N + 1];
pair<int, int> tree[MAX_N * 4];

pair<int, int> get_max_pair(pair<int, int> a, pair<int, int> b) {
	int temp[4] = { a.first, a.second, b.first, b.second };
	sort(temp, temp + 4);
	return { temp[3], temp[2] };
}

pair<int, int> set_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = { arr[start], 0 };

	int mid = (start + end) / 2;
	return tree[node] = get_max_pair(set_tree(start, mid, node * 2), set_tree(mid + 1, end, node * 2 + 1));
}

pair<int, int> get_max_sum(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return { 0, 0 };
	if (left <= start && end <= right) {
		cout << "get_max_sum(" << start << ", " << end << ", " << node << ", " << left << ", " << right << ") = { " << tree[node].first << " + " <<  tree[node].second << " }\n";
		return tree[node];
	}

	int mid = (start + end) / 2;
	pair<int, int> left_pair = get_max_sum(start, mid, node * 2, left, right);
	pair<int, int> right_pair = get_max_sum(mid + 1 , end, node * 2 + 1, left, right);
	return get_max_pair(left_pair, right_pair);
}

void update(int start, int end, int node, int index, int value) {
	if (start > index || end < index)	return;
	if (start == end && end == index) {
		tree[node] = { value, 0 };
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, value);
	update(mid + 1, end, node * 2 + 1, index, value);

	tree[node] = get_max_pair(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	set_tree(1, N, 1);

	int M;
	cin >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c);
		}
		else {
			pair<int, int> maximum = get_max_sum(1, N, 1, b, c);
			cout << maximum.first + maximum.second << "\n";
		}
	}
	return 0;
}