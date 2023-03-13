#include <iostream>

using namespace std;

#define MAX_N 500'000

int arr[MAX_N + 1];
int tree[4 * MAX_N];

int set_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = set_tree(start, mid, node * 2) + set_tree(mid + 1, end, node * 2 + 1);
}


int get_unit(int start, int end, int node, int number) {
	if (start == end)	return start;
	int left = tree[node * 2];
	int right = tree[node * 2 + 1];

	int mid = (start + end) / 2;
	if (left < number) return get_unit(mid + 1, end, node * 2 + 1, number - left);
	else	return get_unit(start, mid, node * 2, number);
}

void update(int start, int end, int node, int unit, int value) {
	if (start > unit || unit > end)	return;

	tree[node] += value;
	if (start == end)	return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, unit, value);
	update(mid + 1, end, node * 2 + 1, unit, value);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int M;
	cin >> M;

	set_tree(1, N, 1);

	int cmd, A, B;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> A >> B;
			update(1, N, 1, A, B);
		}
		else {
			cin >> A;
			cout << get_unit(1, N, 1, A) << "\n";
		}
	}
	return 0;
}