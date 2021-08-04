//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[12] = { 0, };
//	arr[1] = 1;
//	arr[2] = 2;
//	arr[3] = 4;
//	for (int i = 4; i <= 11; i++) {
//		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
//	}
//	int testcase;
//	cin >> testcase;
//	while (testcase--) {
//		int num;
//		cin >> num;
//		cout << arr[num] << "\n";
//	}
//	return 0;
//}