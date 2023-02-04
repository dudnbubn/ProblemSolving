#include <iostream>
#include <unordered_set>

using namespace std;

int N;
int arr[100000];
int tree[400000];
int result[400000];
unordered_set<int> is_leaf;

void set_tree(int start, int end, int node) {
	tree[node] = end - start + 1;
	if (start == end) {
		is_leaf.insert(node);
		return;
	}
	int mid = (start + end) / 2;
	set_tree(start, mid, node * 2);
	set_tree(mid + 1, end, node * 2 + 1);
}

void set_number(int start, int end, int node, int target, int weight) {
	tree[node]--;
	if (is_leaf.find(node) != is_leaf.end()) {
		result[node] = target;
		return;
	}

	int left = tree[node * 2];
	int right = tree[node * 2 + 1];
	int mid = (start + end) / 2;
	if (arr[target] < weight + left)
		set_number(start, mid, node * 2, target, weight);
	else
		set_number(mid + 1, end, node * 2 + 1, target, weight + left);
}

void inorder_traversal(int node) {
	bool leaf = (is_leaf.find(node) != is_leaf.end());
	if (!leaf)
		inorder_traversal(node * 2);
	if(leaf)
		cout << result[node] << "\n";
	if (!leaf)
		inorder_traversal(node * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	
	set_tree(1, N, 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		set_number(1, N, 1, i, 0);
	}

	inorder_traversal(1);
	return 0;
}