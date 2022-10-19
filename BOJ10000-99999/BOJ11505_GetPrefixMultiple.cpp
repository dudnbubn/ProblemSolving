#include <iostream>

using namespace std;

#define MAX_SIZE 1000000
#define MOD 1000000007

int arr[MAX_SIZE + 1];
long long tree[4 * MAX_SIZE];

long long getTree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = (getTree(start, mid, node * 2) * getTree(mid + 1, end, node * 2 + 1)) % MOD;
}

long long getMul(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 1;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return (getMul(start, mid, node * 2, left, right) * getMul(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

void update(int start, int end, int node, int index, int change) {
	if (index < start || end < index)	return;

	tree[node] = (tree[node] * change) % MOD;
	if (start == end)	return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, change);
	update(mid + 1, end, node * 2 + 1, index, change);
}

long long power(long long base, long long expo) {
	long long result = 1;
	while (expo) {
		if (expo & 1)	result = (result * base) % MOD;
		base = (base * base) % MOD;
		expo >>= 1;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)	cin >> arr[i];

	getTree(1, N, 1);

	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			if (arr[b] == 0) {
				arr[b] = c;
				getTree(1, N, 1);
			}
			else {
				update(1, N, 1, b, power(arr[b], MOD - 2) * c % MOD);
				arr[b] = c;
			}
		}
		else {
			cout << getMul(1, N, 1, b, c) << '\n';
		}
	}
	return 0;
}