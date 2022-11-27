#include <iostream>

using namespace std;

int arr[100001];
int tree[400000];
long long result;

int get_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = start;

	int mid = start + end >> 1;
	int left_index = get_tree(start, mid, node * 2);
	int right_index = get_tree(mid + 1, end, node * 2 + 1);
	return tree[node] = (arr[left_index] < arr[right_index]) ? left_index : right_index;
}

int get_min_index(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = start + end >> 1;
	int left_index = get_min_index(start, mid, node * 2, left, right);
	int right_index = get_min_index(mid + 1, end, node * 2 + 1, left, right);

	return (arr[left_index] < arr[right_index]) ? left_index : right_index;
}

void get_max_rectangle(int N, int start, int end) {
	if (start == end) {
		result = result > arr[start] ? result : arr[start];
		return;
	}
	int min_index = get_min_index(1, N, 1, start, end);
	long long max_rectangle = (long long)arr[min_index] * (end - start + 1);
	result = result > max_rectangle ? result : max_rectangle;
	if(start < min_index)	get_max_rectangle(N, start, min_index - 1);
	if(min_index < end)	get_max_rectangle(N, min_index+1, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	arr[0] = 1000000001;
	while (N) {
		result = 0;
		for (int i = 1; i <= N; i++)	cin >> arr[i];
		get_tree(1, N, 1);
		get_max_rectangle(N, 1, N);
		cout << result << "\n";
		

		cin >> N;
	}
	return 0;
}