//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int A, B, m;
//	cin >> A >> B >> m;
//	int decimal = 0, mul = 1;
//	int arr[25];
//	for (int i = 0; i < m; i++)
//		cin >> arr[i];
//	for (int i = m - 1; i >= 0; i--) {
//		decimal += (mul * arr[i]);
//		mul *= A;
//	}
//	stack<int> answer;
//	while (decimal != 0) {
//		answer.push(decimal % B);
//		decimal /= B;
//	}
//	while (!answer.empty()) {
//		cout << answer.top() << " ";
//		answer.pop();
//	}
//	return 0;
//}