#include <iostream>
#include <unordered_map>

using namespace std;

int arr[100001];
int tree[400000];
int index_of[100001];
unordered_map<int, int> leaf;

void set_tree(int start, int end, int node) {
	if (start == end) {
		leaf[start] = node;
		return;
	}
	int mid = (start + end) / 2;
	set_tree(start, mid, node * 2);
	set_tree(mid + 1, end, node * 2 + 1);
}

int get_visited_count(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];
	
	int mid = (start + end) / 2;
	return get_visited_count(start, mid, node * 2, left, right) + get_visited_count(mid + 1, end, node * 2 + 1, left, right);
}

void update(int number) {
	int node = leaf[number];
	while (node) {
		tree[node]++;
		node /= 2;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		index_of[arr[i]] = i;
	}
	set_tree(1, N, 1);

	int start = 1, end = N, index;
	bool flag = true;
	while (start <= end) {
		if (flag) {
			index = index_of[start];
			cout << index - 1 - get_visited_count(1, N, 1, 1, index - 1) << "\n";
			update(index_of[start]);
			start++;
		}
		else {
			index = index_of[end];
			cout << N - index - get_visited_count(1, N, 1, index + 1, N) << "\n";
			update(index_of[end]);
			end--;
		}
		flag = !flag;
	}
	return 0;
}