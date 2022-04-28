//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int n, m;
//int arr[100001];
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		pq.push({ arr[i], i });
//	}
//
//	cin >> m;
//	int cmd, index, v;
//	for (int i = 0; i < m; i++) {
//		cin >> cmd;
//		if (cmd == 1) {
//			cin >> index >> v;
//			arr[index] = v;
//			pq.push({ v, index });
//		}
//		else {
//			while (arr[pq.top().second] != pq.top().first)
//				pq.pop();
//			cout << pq.top().second << "\n";
//		}
//	}
//	return 0;
//}