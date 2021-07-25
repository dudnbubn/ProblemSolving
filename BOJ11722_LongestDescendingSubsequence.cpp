//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int A[1001];
//int cache[1001];
//pair<int, int> idxnum[1001];
//
//int LDS() {
//	int index = 0;
//	cache[0] = A[n - 1];
//	idxnum[0] = { index, A[0] };
//	for (int i = n - 2; i >= 0; i--) {
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
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> A[i];
//	cout << LDS();
//	return 0;
//}