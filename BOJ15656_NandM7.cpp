//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int n, m;
//int arr[8];
//vector<int> answer;
//
//void DFS(int k) {
//	if (k == m) {
//		for (int i = 0; i < k; i++)
//			cout << answer[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		answer.push_back(arr[i]);
//		DFS(k + 1);
//		answer.pop_back();
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
//	DFS(0);
//
//	return 0;
//}