//#include <iostream>
//using namespace std;
//
//int main() {
//	int n, b;
//	char arr[36];
//	for (int i = 0; i < 36; i++) {
//		if (i < 10)
//			arr[i] = (char)(i + '0');
//		else
//			arr[i] = (char)(i - 10 + 'A');
//	}
//	cin >> n >> b;
//	string answer = "";
//	while (n != 0) {
//		answer = arr[n % b] + answer;
//		n = n / b;
//	}
//	cout << answer;
//	return 0;
//}