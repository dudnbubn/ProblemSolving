#include <iostream>

using namespace std;

#define MAX_N 100'000
#define MAX_VALUE 1'000'000

int arr[MAX_N + 1];
int tree[MAX_N * 4];
long long result;

int set_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = start;

	int mid = (start + end) / 2;

	int left_index = set_tree(start, mid, node * 2);
	int right_index = set_tree(mid + 1, end, node * 2 + 1);
	return tree[node] = arr[left_index] < arr[right_index] ? left_index : right_index;
}

int get_min_index(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	int left_index = get_min_index(start, mid, node * 2, left, right);
	int right_index = get_min_index(mid + 1, end, node * 2 + 1, left, right);
	return arr[left_index] < arr[right_index] ? left_index : right_index;
}

void get_max_rectangle(int N, int start, int end) {
	if (start == end) {
		result = result > arr[start] ? result : arr[start];
		return;
	}

	int min_index = get_min_index(1, N, 1, start, end);
	long long area = (long long)arr[min_index] * (end - start + 1);
	result = result > area ? result : area;

	if (min_index < end)	get_max_rectangle(N, min_index + 1, end);
	if (min_index > start)	get_max_rectangle(N, start, min_index - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	arr[0] = MAX_VALUE + 1;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	set_tree(1, N, 1);

	get_max_rectangle(N, 1, N);
	cout << result;
	return 0;
	
}