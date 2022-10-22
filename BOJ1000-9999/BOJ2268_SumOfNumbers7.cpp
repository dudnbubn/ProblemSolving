//#include <iostream>
//
//using namespace std;
//
//#define MAX_SIZE 1000000
//
//int arr[MAX_SIZE + 1];
//long long tree[MAX_SIZE * 4];
//
//long long getTree(int start, int end, int node) {
//	if (start == end)	return tree[node] = arr[start];
//
//	int mid = (start + end) / 2;
//	return tree[node] = getTree(start, mid, node * 2) + getTree(mid + 1, end, node * 2 + 1);
//}
//
//long long getSum(int start, int end, int node, int left, int right) {
//	if (start > right || end < left)	return 0;
//	if (left <= start && end <= right)	return tree[node];
//
//	int mid = (start + end) / 2;
//	return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
//}
//
//void update(int start, int end, int node, int index, int change) {
//	if (index < start || end < index)	return;
//
//	tree[node] += change;
//	if (start == end)	return;
//	int mid = (start + end) / 2;
//
//	update(start, mid, node * 2, index, change);
//	update(mid + 1, end, node * 2 + 1, index, change);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int N, M;
//	cin >> N >> M;
//
//	int a, b, c;
//	for (int i = 0; i < M; i++) {
//		cin >> a >> b >> c;
//		if (a) {
//			update(1, N, 1, b, c - arr[b]);
//			arr[b] = c;
//		}
//		else {
//			if (b < c)	cout << getSum(1, N, 1, b, c) << "\n";
//			else		cout << getSum(1, N, 1, c, b) << "\n";
//		}
//	}
//	return 0;
//}