//#include <iostream>
//
//using namespace std;
//
//long long arr[1000001];
//long long tree[4000000];
//
//long long getSum(int start, int end, int node, int left, int right) {
//	if (start > right || end < left)	return 0;
//	if (left <= start && end <= right)	return tree[node];
//
//	int mid = (start + end) / 2;
//	return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
//}
//
//void update(int start, int end, int node, int index, long long change) {
//	if (index < start || index > end)	return;
//
//	tree[node] += change;
//	if (start == end)	return;
//	int mid = (start + end) / 2;
//	update(start, mid, node * 2, index, change);
//	update(mid + 1, end, node * 2 + 1, index, change);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int N, Q;
//	cin >> N >> Q;
//	int cmd, a, b;
//	for (int i = 0; i < Q; i++) {
//		cin >> cmd >> a >> b;
//
//		if (cmd == 1) {
//			update(1, N, 1, a, b);
//			arr[a] += b;
//		}
//		else {
//			cout << getSum(1, N, 1, a, b) << "\n";
//		}
//	}
//	return 0;
//}