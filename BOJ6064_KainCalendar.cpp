//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int LCM(int a, int b) {
//	int mul = a * b;
//	int n = min(a, b);
//	a = max(a, b);
//	b = n;
//	n = a % b;
//	while (n != 0) {
//		a = b;
//		b = n;
//		n = a % b;
//	}
//	return mul / b;
//}
//
//int main() {
//	int testcase;
//	cin >> testcase;
//	int m, n, x, y;
//	while (testcase--) {
//		cin >> m >> n >> x >> y;
//		int lcm = LCM(m, n);
//		bool flag = true;
//		while (x <= lcm && y <= lcm) {
//			if (x == y) {
//				flag = false;
//				cout << x << "\n";
//				break;
//			}
//			else if (x > y) {
//				y += n;
//			}
//			else
//				x += m;
//		}
//		if (flag)
//			cout << -1 << "\n";
//	}
//}