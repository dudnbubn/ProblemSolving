#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100'000
#define INF 1'000'000

int arr[MAX_N + 1];
int tree[4 * MAX_N];
long long result = 0;

int set_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = start;

	int mid = (start + end) / 2;
	int left_min = set_tree(start, mid, node * 2);
	int right_min = set_tree(mid + 1, end, node * 2 + 1);
	return tree[node] = arr[left_min] < arr[right_min] ? left_min : right_min;
}

int get_min_index(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	int left_min = get_min_index(start, mid, node * 2, left, right);
	int right_min = get_min_index(mid + 1, end, node * 2 + 1, left, right);
	return arr[left_min] < arr[right_min] ? left_min : right_min;
}

void get_max_profit(int start, int end, int N) {
	if (start == end) {
		result = result > arr[start] ? result : arr[start];
		return;
	}

	int min_index = get_min_index(1, N, 1, start, end);
	long long score = (long long)arr[min_index] * (end - start + 1);

	result = result > score ? result : score;
	if (start < min_index)		get_max_profit(start, min_index - 1, N);
	if (end > min_index)		get_max_profit(min_index + 1, end, N);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	arr[0] = INF;
	set_tree(1, N, 1);
	
	get_max_profit(1, N, N);
	cout << result;
	return 0;
}