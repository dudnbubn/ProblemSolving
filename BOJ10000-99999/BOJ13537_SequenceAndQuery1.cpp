#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100'000

int arr[MAX_N + 1];
vector<int> tree[4 * MAX_N];

vector<int> merge(vector<int> a, vector<int> b) {
	if (a.empty())	return b;
	if (b.empty())	return a;

	int a_size = a.size();
	int b_size = b.size();
	int result_size = a_size + b_size;

	vector<int> result(result_size);
	int a_index = 0;
	int b_index = 0;
	int result_index = 0;

	while (result_index < result_size) {
		if (a_index == a_size) {
			while (b_index < b_size)
				result[result_index++] = b[b_index++];
		}
		else if (b_index == b_size) {
			while (a_index < a_size)
				result[result_index++] = a[a_index++];
		}
		else {
			if (a[a_index] < b[b_index])
				result[result_index++] = a[a_index++];
			else
				result[result_index++] = b[b_index++];
		}
	}
	return result;
}

vector<int> set_tree(int start, int end, int node) {
	if (start == end) {
		tree[node].push_back(arr[start]);
		return tree[node];
	}

	int mid = (start + end) / 2;
	return tree[node] = merge(set_tree(start, mid, node * 2), set_tree(mid + 1, end, node * 2 + 1));
}

void get_sorted_vectors(vector<vector<int>*> &sorted_vectors, int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return;
	if (left <= start && end <= right) {
		sorted_vectors.push_back(&tree[node]);
		return;
	}

	int mid = (start + end) / 2;
	get_sorted_vectors(sorted_vectors, start, mid, node * 2, left, right);
	get_sorted_vectors(sorted_vectors, mid + 1, end, node * 2 + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int n = 1; n <= N; n++)	cin >> arr[n];
	set_tree(1, N, 1);

	int M;
	cin >> M;

	int i, j, k;
	int result, index;
	vector<vector<int>*> sorted_vectors;
	for (int m = 0; m < M; m++) {
		cin >> i >> j >> k;

		sorted_vectors = {};
		get_sorted_vectors(sorted_vectors, 1, N, 1, i, j);
		result = 0;
		for (vector<int>* sorted_vector : sorted_vectors) {
			index = upper_bound(sorted_vector->begin(), sorted_vector->end(), k) - sorted_vector->begin();
			result += (sorted_vector->size() - index);
		}
		cout << result << "\n";
	}
	return 0;
}