//// 모든 버튼이 고장날 수도 있음에 주의...
//
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//int n, m;
//int nsz = 0;
//bool broken[10] = { 0, };
//int upperBound = 1000000;
//int lowerBound = -1;
//int ubsz = 1, lbsz = 1;
//
//void Combination(int value) {
//	if (value > n) {
//		if (upperBound > value)
//			upperBound = value;
//		return;
//	}
//	if (lowerBound < value) 
//		lowerBound = value;
//	for (int i = 0; i < 10; i++) {
//		if (!broken[i]) {
//			if (i == 0 && value == 0) continue;
//			Combination(value * 10 + i);
//		}
//	}
//}
//
//int main() {
//	int minimum = 500000;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int num;
//		cin >> num;
//		broken[num] = true;
//	}
//	if (m == 10) {
//		cout << abs(n - 100);
//		return 0;
//	}
//	if (minimum > abs(n - 100))
//		minimum = abs(n - 100);
//	for (int i = 0; i < 10; i++) {
//		if (!broken[i]) {
//			if (lowerBound == -1)
//				lowerBound = i;
//			Combination(i);
//		}
//	}
//	int mul = 10;
//	for (int i = 0; i < 8; i++) {
//		if (upperBound / mul != 0)
//			ubsz++;
//		if (lowerBound / mul != 0)
//			lbsz++;
//		mul *= 10;
//	}
//	minimum = min({ minimum, ubsz + (upperBound - n), lbsz + abs(n - lowerBound) });
//	cout << minimum;
//	return 0;
//}