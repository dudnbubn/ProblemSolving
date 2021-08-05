//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int arr[8];
//int answer[8];
//int maximum = 0;
//bool isUsed[8];
//
//void DFS(int k) {
//	if (k == n) {
//		int sum = 0;
//		for (int i = 0; i < n - 1; i++) {
//			sum += abs(answer[i] - answer[i + 1]);
//		}
//		maximum = max(sum, maximum);
//		return;
//	}
//
//	for (int i = 0; i < n; i++) {
//		if (!isUsed[i]) {
//			isUsed[i] = true;
//			answer[k] = arr[i];
//			DFS(k + 1);
//			isUsed[i] = false;
//		}
//	}
//}
//
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	DFS(0);
//	cout << maximum;
//	return 0;
//}