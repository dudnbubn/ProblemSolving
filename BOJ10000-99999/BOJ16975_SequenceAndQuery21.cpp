#include <iostream>

using namespace std;

int arr[100001];
int tree[400000];

void set_value(int start, int end, int node, int left, int right, int value) {
	if (start > right || end < left)	return;
	if (left <= start && end <= right) {
		tree[node] += value;
		return;
	}

	int mid = (start + end) / 2;
	set_value(start, mid, node * 2, left, right, value);
	set_value(mid + 1, end, node * 2 + 1, left, right, value);
}

long long get_value(int start, int end, int node, int target) {
	if (start == end && start == target)	return tree[node];
	if (start > target || end < target)	return 0;

	int mid = (start + end) / 2;
	if (target <= mid)	return tree[node] + get_value(start, mid, node * 2, target);
	else	return tree[node] + get_value(mid + 1, end, node * 2 + 1, target);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	cin >> M;
	int cmd, a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b >> c;
			set_value(1, N, 1, a, b, c);
		}
		else {
			cin >> a;
			cout << arr[a] + get_value(1, N, 1, a) << "\n";
		}
	}
	return 0;
}