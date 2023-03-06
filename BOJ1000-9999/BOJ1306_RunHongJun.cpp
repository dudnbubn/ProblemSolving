#include <iostream>
#include <algorithm>

using namespace std;

#define LENGTH 1'000'000

int arr[LENGTH + 1];
int tree[4 * LENGTH];

int set_max_tree(int start, int end, int node) {
	if (start == end) 
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	
	return tree[node] = max(set_max_tree(start, mid, node * 2), set_max_tree(mid + 1, end, node * 2 + 1));
}

int get_max_value(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return max(get_max_value(start, mid, node * 2, left, right), get_max_value(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)	cin >> arr[i];

	set_max_tree(1, N, 1);
	for (int i = M; i <= N - M + 1; i++)
		cout << get_max_value(1, N, 1, i - (M - 1), i + M - 1) << " ";
	return 0;
}