//#include <iostream>
//using namespace std;
//
//bool circle[5001];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL);
//
//	// n명의 사람들 중에서 k 번째 사람을 제거
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//		circle[i] = true;
//
//	cout << "<";
//	int cnt = 0, index = 0;
//	for (int i = 0; i < n; i++) {
//		while (cnt < k) {
//			if (circle[index]) {
//				cnt++;
//				if (cnt == k) {
//					cout << index + 1;
//					circle[index] = false;
//					if (i != n - 1)
//						cout << ", ";
//				}
//			}
//			index = (index + 1) % n;
//		}
//		cnt = 0;
//	}
//	cout << ">";
//
//	return 0;
//}