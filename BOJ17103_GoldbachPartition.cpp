//#include <iostream>
//using namespace std;
//
//bool isPrime[1000000];
//int goldbach[1000001] = { 0, };
//
//void Eratos() {
//	for (int i = 2; i < 1000000; i++)
//		isPrime[i] = true;
//	for (int i = 2; i * i < 1000000; i++) {
//		if (isPrime[i]) {
//			for (int j = i * i; j < 1000000; j += i)
//				isPrime[j] = false;
//		}
//	}
//}
//
//int Goldbach(int n) {
//	if (goldbach[n] != 0)
//		return goldbach[n];
//	for (int i = 2; i <= n/2; i++) {
//		if (isPrime[i] && isPrime[n - i]) {
//			goldbach[n]++;
//		}
//	}
//	return goldbach[n];
//}
//int main() {
//	int testcase;
//	cin >> testcase;
//	Eratos();
//	while (testcase--) {
//		int num;
//		cin >> num;
//		cout << Goldbach(num) << "\n";
//	}
//	return 0;
//}