//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int n, m;
//int arr[8];
//vector<int> answer;
//
//void DFS(int k, int p) {
//	if (k == m) {
//		for (int i = 0; i < k; i++)
//			cout << answer[i] << " ";
//		cout << "\n";
//		return;
//	}
//	int prev = 0;
//	for (int i = 0; i < n; i++) {
//		if ((prev != arr[i]) && (i >= p)) {
//			prev = arr[i];
//			answer.push_back(arr[i]);
//			DFS(k + 1, i);
//			answer.pop_back();
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	sort(arr, arr + n);
//	DFS(0, 0);
//
//	return 0;
//}