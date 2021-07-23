//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int A[1000];
//int cache[1000];
//int n;
//
//int LIS() {
//	int index = 0;
//	cache[0] = A[0];
//	for (int i = 1; i < n; i++) {
//		if (A[i] > cache[index]) {
//			index++;
//			cache[index] = A[i];
//		}
//		else {
//			int index2 = lower_bound(cache, cache + index, A[i]) - cache;
//			cache[index2] = A[i];
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
//	cout << LIS();
//	return 0;
//}