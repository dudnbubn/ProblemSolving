#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[1000001];
int tree[4000000];
int leaf[1000001];

void set_tree(int start, int end, int node) {
	if (start == end) {
		leaf[start] = node;
		return;
	}
	int mid = (start + end) / 2;
	set_tree(start, mid, node * 2);
	set_tree(mid + 1, end, node * 2 + 1);
}

int get_value(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return get_value(start, mid, node * 2, left, right) + get_value(mid + 1, end, node * 2 + 1, left, right);
}

void update(int index) {
	int node = leaf[index];
	while (node) {
		tree[node]++;
		node /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].second;
		arr[i].first = i;
	}
	set_tree(1, N, 1);
	sort(arr + 1, arr + N + 1);

	int index;

	long long result = 0;
	for (int i = 1; i <= N; i++) {
		index = arr[i].second;
		result += (index - 1 - get_value(1, N, 1, 1, index - 1));
		update(index);
	}
	cout << result;
	return 0;
}