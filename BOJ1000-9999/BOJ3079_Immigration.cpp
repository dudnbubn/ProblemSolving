//#include <iostream>
//
//using namespace std;
//
//int N, M;
//int T[100001];
//
//int main() {
//	long long start = 0, end = 0;
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		cin >> T[i];
//		end = end > T[i] ? end : T[i];
//	}
//	end *= M;
//	
//	long long cnt;
//	while (start <= end) {
//		long long mid = (start + end) / 2;
//		cnt = 0;
//		for (int i = 0; i < N; i++) 
//			cnt += mid / T[i];
//		
//		if (cnt < M)	start = mid + 1;
//		else	end = mid - 1;
//	}
//
//	cout << start;
//	return 0;
//}