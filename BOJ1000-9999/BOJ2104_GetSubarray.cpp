#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100'000

int arr[MAX_N + 1];
int min_tree[4 * MAX_N];
long long sum_tree[4 * MAX_N];
long long result;

int set_min_tree(int start, int end, int node) {
	if (start == end)	return min_tree[node] = start;

	int mid = (start + end) / 2;
	int left_index = set_min_tree(start, mid, node * 2);
	int right_index = set_min_tree(mid + 1, end, node * 2 + 1);

	return min_tree[node] = arr[left_index] < arr[right_index] ? left_index : right_index;
}

int get_min_index(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return min_tree[node];

	int mid = (start + end) / 2;
	int left_index = get_min_index(start, mid, node * 2, left, right);
	int right_index = get_min_index(mid + 1, end, node * 2 + 1, left, right);
	
	return (arr[left_index] < arr[right_index] ? left_index : right_index);
}

long long set_sum_tree(int start, int end, int node) {
	if (start == end)	return sum_tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	return sum_tree[node] = set_sum_tree(start, mid, node * 2) + set_sum_tree(mid + 1, end, node * 2 + 1);
}

long long get_sum(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return sum_tree[node];

	int mid = (start + end) / 2;
	return get_sum(start, mid, node * 2, left, right) + get_sum(mid + 1, end, node * 2 + 1, left, right);
}

void get_max_score(int N, int left, int right) {
	long long max_score, sum, min_index;
	if (left == right) {
		max_score = (long long)arr[left] * arr[left];
		result = result > max_score ? result : max_score;
		return;
	}
	sum = get_sum(1, N, 1, left, right);
	min_index = get_min_index(1, N, 1, left, right);
	max_score = sum * arr[min_index];
	result = result > max_score ? result : max_score;
	
	if (left != min_index)	get_max_score(N, left, min_index - 1);
	if (right != min_index)	get_max_score(N, min_index + 1, right);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	
	arr[0] = 1'000'001;

	set_min_tree(1, N, 1);
	set_sum_tree(1, N, 1);
	
	get_max_score(N, 1, N);
	cout << result;
	return 0;
}