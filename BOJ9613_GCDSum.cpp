//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int Euclid(int a, int b) {
//	int n = min(a, b);
//	a = max(a, b);
//	b = n;
//	n = a % b;
//	while (n != 0) {
//		a = b;
//		b = n;
//		n = a % b;
//	}
//	return b;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	int testcase, n;
//	int arr[100] = { 0, };
//	cin >> testcase;
//	while (testcase--) {
//		cin >> n;
//		long long sum = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		for (int i = 0; i < n - 1; i++) {
//			for (int j = i + 1; j < n; j++) {
//				sum += Euclid(arr[i], arr[j]);
//			}
//		}
//		cout << sum << "\n";
//	}
//
//	return 0;
//}