#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100'000
#define MAX_VALUE 1'000'000'000

int arr[MAX_N + 1];
vector<int> tree[MAX_N * 4];

vector<int> merge(vector<int> a, vector<int> b) {
	if (a.empty())	return b;
	if (b.empty())	return a;

	int a_size = a.size();
	int b_size = b.size();
	int result_size = a_size + b_size;
	vector<int> result(result_size);
	int a_index = 0, b_index = 0, result_index = 0;
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

int binary_search(vector<vector<int>*> &sorted_vectors, int k) {
	int start = (MAX_VALUE + 1) * (-1), end = MAX_VALUE + 1;
	int mid, min_count;

	while (start < end) {
		if (start + end >= 0)
			mid = (start + end) / 2;
		else
			mid = (start + end - 1) / 2;

		min_count = 0;
		for (vector<int>* sorted_vector : sorted_vectors) {
			min_count += lower_bound(sorted_vector->begin(), sorted_vector->end(), mid) - sorted_vector->begin();
		}

		if (min_count < k)	start = mid + 1;
		else	end = mid;
	}
	return start - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	set_tree(1, N, 1);

	vector<vector<int>*> sorted_vectors;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		sorted_vectors = {};
		get_sorted_vectors(sorted_vectors, 1, N, 1, a, b);

		cout << binary_search(sorted_vectors, c) << "\n";
	}
	return 0;
}