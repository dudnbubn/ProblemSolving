#include <iostream>

using namespace std;

int N;
int arr[1000001];
int tree[4000000];

int euclid(int a, int b) {
	int n = a > b ? a : b;
	b = a < b ? a : b;
	a = n;
	n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int set_tree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = euclid(set_tree(start, mid, node * 2), set_tree(mid + 1, end, node * 2 + 1));
}

int get_gcd(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	int left_gcd = get_gcd(start, mid, node * 2, left, right);
	int right_gcd = get_gcd(mid + 1, end, node * 2 + 1, left, right);
	
	if (left_gcd == 0)	return right_gcd;
	else if (right_gcd == 0)	return left_gcd;
	else	return euclid(left_gcd, right_gcd);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	set_tree(1, N, 1);

	int maximum = -1;
	int index = 0;
	int gcd, left_gcd, right_gcd;
	for (int i = 1; i <= N; i++) {
		left_gcd = get_gcd(1, N, 1, 1, i - 1);
		right_gcd = get_gcd(1, N, 1, i + 1, N);

		if (left_gcd == 0)	gcd = right_gcd;
		else if (right_gcd == 0)	gcd = left_gcd;
		else	gcd = euclid(left_gcd, right_gcd);

		if (gcd == 0 || arr[i] % gcd == 0)	continue;
		
		if (maximum < gcd) {
			maximum = gcd;
			index = i;
		}
	}

	if (maximum == -1)	cout << -1;
	else	cout << maximum << " " << arr[index];

	return 0;
}