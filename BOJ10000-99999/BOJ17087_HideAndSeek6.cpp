//// ��� ������ ���ؼ� ��ġ A[i] - S �� ������ ���Ͽ� ������ �Ÿ��� ����Ѵ�.
//// ��� ������ �Ÿ��� �ִ������� �� ������ ���� �ȴ�.
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int Euclid(int a, int b) {
//	int n = min(a, b);
//	a = max(a, b);
//	b = n;
//	n = a % b;
//	while (n != 0) {
//		a = b;
//		b = n;
//		n = a % b;
//	}
//	return b;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	int n, s, gcd;
//	cin >> n >> s;
//	int* A = new int[n];
//	
//	for (int i = 0; i < n; i++) {
//		cin >> A[i];
//		if (A[i] < s)
//			A[i] = s - A[i];
//		else
//			A[i] = A[i] - s;
//
//		if (i == 0)
//			gcd = A[i];
//		else
//			gcd = Euclid(gcd, A[i]);
//	}
//	cout << gcd;
//	return 0;
//}