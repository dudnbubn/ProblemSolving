//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int arr[10000];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int T;
//	cin >> T;
//
//	int n;
//	while (T--) {
//		cin >> n;
//		for (int i = 0; i < n; i++)	cin >> arr[i];
//		cout << (n + 1) / 2 << "\n" << arr[0] << " ";
//		for (int i = 1; i < n; i++) {
//			if (i % 2 == 0) {
//				sort(arr, arr + i + 1);
//				if (i % 20 == 0)	cout << "\n";
//				cout << arr[i / 2] << " ";
//			}
//		}
//		cout << "\n";
//	}
//}