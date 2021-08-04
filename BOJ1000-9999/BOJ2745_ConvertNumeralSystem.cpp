//#include <iostream>
//using namespace std;
//
//int main() {
//	string n;
//	int b;
//	cin >> n >> b;
//	int answer = 0;
//	int mul = 1;
//	for (int i = n.size() - 1; i >= 0; i--) {
//		int temp;
//		if (n[i] >= 'A')
//			temp = n[i] - 'A' + 10;
//		else
//			temp = n[i] - '0';
//		answer += (temp * mul);
//		mul *= b;
//	}
//	cout << answer;
//	return 0;
//}