#include <iostream>

using namespace std;

int arr[500001];
int tree[2000000];

int XOR(int a, int b) {
	int result = 0;
	for (int i = 0; a || b; i++, a /= 2, b /= 2) {
		if (a % 2 != b % 2)	result |= (1 << i);
	}
	return result;
}

void set_xor(int start, int end, int node, int left, int right, int value) {
	if (start > right || end < left)	return;
	
	if (left <= start && end <= right) {
		tree[node] = XOR(tree[node], value);
		return;
	}

	int mid = (start + end) / 2;
	set_xor(start, mid, node * 2, left, right, value);
	set_xor(mid + 1, end, node * 2 + 1, left, right, value);
}

int get_xor(int start, int end, int node, int target) {
	if (start == end && start == target)	return tree[node];
	if (start > target || end < target)		return 0;

	int mid = (start + end) / 2;
	if (target <= mid)	return XOR(tree[node], get_xor(start, mid, node * 2, target));
	else	return XOR(tree[node], get_xor(mid + 1, end, node * 2 + 1, target));
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

	int cmd ,a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b >> c;
			set_xor(1, N, 1, a + 1, b + 1, c);
		}
		else {
			cin >> a;
			cout << XOR(arr[a + 1], get_xor(1, N, 1, a + 1)) << "\n";
		}
	}
}