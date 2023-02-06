#include <iostream>

using namespace std;

int arr[100001];
bool is_leaf[400000];
int tree[400000];
int result[400000];

int set_tree(int start, int end, int node) {
	if (start == end) {
		is_leaf[node] = true;
		return tree[node] = 1;
	}
	
	int mid = (start + end) / 2;
	return tree[node] = set_tree(start, mid, node * 2) + set_tree(mid + 1, end, node * 2 + 1);
}

void set_number(int start, int end, int node, int target, int weight) {
	tree[node]--;
	if (is_leaf[node]) {
		result[node] = target;
		return;
	}
	
	int left = tree[node * 2];
	int right = tree[node * 2 + 1];
	int mid = (start + end) / 2;
	if (arr[target] >= right + weight)
		set_number(start, mid, node * 2, target, weight + right);
	else
		set_number(mid + 1, end, node * 2 + 1, target, weight);
		
}

void inorder_traversal(int node) {
	if (!is_leaf[node]) {
		inorder_traversal(node * 2);
		inorder_traversal(node * 2 + 1);
	}
	else {
		cout << result[node] << " ";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	set_tree(1, N, 1);

	for (int i = 1; i <= N; i++) 
		cin >> arr[i];

	for (int i = N; i >= 1; i--) {
		set_number(1, N, 1, i, 0);
	}

	inorder_traversal(1);

	return 0;
}