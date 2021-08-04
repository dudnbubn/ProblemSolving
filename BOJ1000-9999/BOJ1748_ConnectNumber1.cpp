//#include <iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	if (n < 10)
//		cout << n;
//	else {
//		int arr[9] = { 0, };
//		int cnt = 9;
//		for (int i = 1; i < 9; i++) {
//			arr[i] = cnt * i;
//			cnt *= 10;
//		}
//		int mul = 1;
//		int len = 0;
//		while (mul <= n) {
//			mul *= 10;
//			len++;
//		}
//		mul /= 10;
//		int answer = (n - mul + 1) * len;
//		for (int i = len - 1; i >= 1; i--)
//			answer += arr[i];
//		cout << answer;
//	}
//	return 0;
//}