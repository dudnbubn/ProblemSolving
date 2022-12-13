//#include <iostream>
//
//using namespace std;
//
//int songs[100001];
//
//int main() {
//	int N;
//	long long T, sum = 0;
//	cin >> N >> T;
//	for (int i = 1; i <= N; i++) {
//		cin >> songs[i];
//		sum += songs[i];
//	}
//
//	T %= sum;
//	for (int i = 1; i <= N; i++) {
//		if (T < songs[i]) {
//			cout << i << " " << T;
//			return 0;
//		}
//		T -= songs[i];
//	}
//}