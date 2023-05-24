#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_X 2'000'000

int tree[MAX_X * 4];
unordered_map<int, int> um;

void set_tree(int start, int end, int node) {
	if (start == end) {
		um[start] = node;
		return;
	}

	int mid = (start + end) / 2;
	set_tree(start, mid, node * 2);
	set_tree(mid + 1, end, node * 2 + 1);
}

void update(int x, int value) {
	int node = um[x];
	while (node) {
		tree[node] += value;
		node /= 2;
	}
}

int get_nth(int start, int end, int node, int x) {
	if (start == end) {
		update(start, -1);
		return start;
	}
	int left = tree[node * 2];
	int right = tree[node * 2 + 1];

	int mid = (start + end) / 2;
	if (left >= x)	get_nth(start, mid, node * 2, x);
	else	get_nth(mid + 1, end, node * 2 + 1, x - left);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	set_tree(1, MAX_X, 1);

	int command, x;
	for (int i = 0; i < N; i++) {
		cin >> command >> x;
		if (command == 1)	update(x, 1);
		else	cout << get_nth(1, MAX_X, 1, x) << "\n";
	}
	return 0;
}