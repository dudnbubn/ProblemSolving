//#include <iostream>
//
//using namespace std;
//
//int N, M;
//int t[10001];
//int ride[10001];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N >> M;
//	for (int i = 1; i <= M; i++)	cin >> t[i];
//
//	if (N <= M) {
//		cout << N;
//		return 0;
//	}
//
//	long long start = 1, end = 60000000000;
//	while (start <= end) {
//		long long mid = (start + end) / 2;
//		
//		long long cnt = 0;
//		for (int i = 1; i <= M; i++)
//			cnt += (mid / t[i] + 1);
//
//		if (cnt < N) start = mid + 1;
//		else	end = mid - 1;
//	}
//
//	for (int i = 1; i <= M; i++) {
//		ride[i] = ((start / t[i]) - (start - 1) / t[i]);
//		N -= (start - 1) / t[i] + 1;
//	}
//
//	for (int i = 1; i <= M; i++) {
//		if (ride[i])	N--;
//		if (N == 0) {
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}