//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//
//using namespace std;
//
//int N;
//int arr[500001];
//int tree[2000000];
//pair<int, int> order[500001];
//unordered_map<int, int> leaf;
//unordered_map<int, int> mapping;
//
//void set_tree(int start, int end, int node) {
//	if (start == end) {
//		leaf[start] = node;
//		return;
//	}
//
//	int mid = (start + end) / 2;
//	set_tree(start, mid, node * 2);
//	set_tree(mid + 1, end, node * 2 + 1);
//}
//
//int get_tree(int start, int end, int node, int left, int right) {
//	if (start > right || end < left)	return 0;
//	if (left <= start && end <= right)	return tree[node];
//
//	int mid = (start + end) / 2;
//	return get_tree(start, mid, node * 2, left, right) + get_tree(mid + 1, end, node * 2 + 1, left, right);
//}
//
//void update(int index) {
//	int node = leaf[index];
//	while (node) {
//		tree[node]++;
//		node /= 2;
//	}
//}
//
//int main() {
//	cin >> N;
//	
//	int number;
//	for (int i = 1; i <= N; i++) {
//		cin >> number;
//		mapping[number] = i;
//	}
//
//	
//	for (int i = 1; i <= N; i++) {
//		cin >> number;
//		arr[i] = mapping[number];
//		order[i] = { mapping[number], i };
//	}
//	set_tree(1, N, 1);
//
//	sort(order + 1, order + N + 1);
//
//	int index;
//	long long result = 0;
//	for (int i = 1; i <= N; i++) {
//		index = order[i].second;
//		result += (index - 1 - get_tree(1, N, 1, 1, index - 1));
//		update(index);
//	}
//	cout << result;
//	return 0;
//}