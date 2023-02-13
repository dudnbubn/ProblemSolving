#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[500001];
int tree[2000000];
int leaf[500001];

priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void set_tree(int start, int end, int node) {
	if (start == end) {
		leaf[start] = node;
		return;
	}

	int mid = (start + end) / 2;
	set_tree(start, mid, node * 2);
	set_tree(mid + 1, end, node * 2 + 1);
}

int get_subsum(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return get_subsum(start, mid, node * 2, left, right) + get_subsum(mid + 1, end, node * 2 + 1, left, right);
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
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pq.push({ arr[i],i });
	}

	set_tree(1, N, 1);
	
	pair<int, int> current;
	int value, index;
	while (!pq.empty()) {
		current = pq.top();
		pq.pop();

		value = current.first;
		index = current.second;
		
		arr[index] = get_subsum(1, N, 1, 1, index - 1);
		update(index);
	}
	
	for (int i = 1; i <= N; i++)
		cout << i - arr[i] << "\n";
	return 0;
}