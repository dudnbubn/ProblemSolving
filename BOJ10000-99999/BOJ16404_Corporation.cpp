#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAX_N 100'000
int parents[MAX_N + 1];
vector<int> children[MAX_N + 1];
pair<int, int> range[MAX_N + 1];

int index = 0;
unordered_map<int, int> employee_to_index;

int tree[MAX_N * 4];
int lazy[MAX_N * 4];

void pre_order_traveling(int current) {
	index++;
	employee_to_index[current] = index;

	for (int child : children[current])
		pre_order_traveling(child);

	range[current] = { employee_to_index[current], index };
}

int get_value(int start, int end, int node, int index) {
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (start > index || end < index)	return 0;
	if (start == end && start == index)	return tree[node];
	
	int mid = (start + end) / 2;
	int result = get_value(start, mid, node * 2, index) + get_value(mid + 1, end, node * 2 + 1, index);
	return result;
}

void update(int start, int end, int node, int left, int right, int profit) {
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (right < start || end < left)	return;
	if (left <= start && end <= right) {
		lazy[node] += profit;
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, profit);
	update(mid + 1, end, node * 2 + 1, left, right, profit);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	
	int parent;
	cin >> parent;
	for (int n = 2; n <= N; n++) {
		cin >> parent;
		children[parent].push_back(n);
		parents[n] = parent;
	}

	pre_order_traveling(1);

	int command, employee, profit;
	int left, right;
	for (int m = 0; m < M; m++) {
		cin >> command;
		if (command == 1) {
			cin >> employee >> profit;
			left = range[employee].first;
			right = range[employee].second;
			update(1, N, 1, left, right, profit);
		}
		else {
			cin >> employee;
			employee = employee_to_index[employee];
			cout << get_value(1, N, 1, employee) << "\n";
		}
	}
	return 0;
}