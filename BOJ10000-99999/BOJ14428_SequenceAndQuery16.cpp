//#include <iostream>
//
//using namespace std;
//
//int arr[100001];
//int tree[400000];
//
//int getTree(int start, int end, int node) {
//	if (start == end)	return tree[node] = start;
//
//	int mid = (start + end) / 2;
//
//	int left = getTree(start, mid, node * 2);
//	int right = getTree(mid + 1, end, node * 2 + 1);
//	if (arr[left] == arr[right])
//		return tree[node] = left < right ? left : right;
//	return tree[node] = arr[left] <= arr[right] ? left : right;
//}
//
//int getIndex(int start, int end, int node, int left, int right) {
//	if (start > right || end < left)	return 0;
//	if (left <= start && end <= right)	return tree[node];
//
//	int mid = (start + end) / 2;
//	int l = getIndex(start, mid, node * 2, left, right);
//	int r = getIndex(mid + 1, end, node * 2 + 1, left, right);
//	if (arr[l] == arr[r]) return (l < r ? l : r);
//	return arr[l] <= arr[r] ? l : r;
//}
//
//void update(int start, int end, int node, int index, int change) {
//	if (index < start || index > end)	return;
//
//	if (start == end) {
//		tree[node] = index;
//	}
//	else {
//		int mid = (start + end) / 2;
//		update(start, mid, node * 2, index, change);
//		update(mid + 1, end, node * 2 + 1, index, change);
//
//		int l = tree[node * 2];
//		int r = tree[node * 2 + 1];
//		if (arr[l] == arr[r])	tree[node] = (l < r ? l : r);
//		tree[node] = arr[l] <= arr[r] ? l : r;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int N, M;
//	cin >> N;
//	arr[0] = 1000000001;
//	for (int i = 1; i <= N; i++)	cin >> arr[i];
//
//	getTree(1, N, 1);
//
//	cin >> M;
//	int a, b, c;
//	for (int i = 0; i < M; i++) {
//		cin >> a >> b >> c;
//		if (a == 1) {
//			arr[b] = c;
//			update(1, N, 1, b, c);
//		}
//		else {
//			cout << getIndex(1, N, 1, b, c) << "\n";
//		}
//	}
//	return 0;
//}