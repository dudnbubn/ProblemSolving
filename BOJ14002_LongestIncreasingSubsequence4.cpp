//#include <iostream>
//#include <algorithm>
//#include <stack>
//using namespace std;
//
//int A[1000];
//int cache[1000];
//int n;
//pair<int, int> idxnum[1000];
//
//int LIS() {
//	int index = 0;
//	cache[0] = A[0];
//	idxnum[0] = { 0, A[0] };
//
//	for (int i = 1; i < n; i++) {
//		if (A[i] > cache[index]) {
//			index++;
//			cache[index] = A[i];
//			idxnum[i] = { index, A[i] };
//		}
//		else {
//			int index2 = lower_bound(cache, cache + index, A[i]) - cache;
//			cache[index2] = A[i];
//			idxnum[i] = { index2, A[i] };
//		}
//	}
//	return index + 1;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> A[i];
//
//	int len = LIS();
//	cout << len << "\n";
//
//	stack<int> stk;
//	for (int i = n - 1; i >= 0; i--) {
//		if (len == 0)
//			break;
//		if (idxnum[i].first == len - 1) {
//			stk.push(idxnum[i].second);
//			len--;
//		}
//	}
//	while (!stk.empty()) {
//		cout << stk.top() << " ";
//		stk.pop();
//	}
//
//	return 0;
//}