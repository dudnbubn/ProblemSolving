//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int n, m;
//int p[1000];
//
//int main() {
//	cin >> n >> m;
//	int end = 0;
//	for (int i = 0; i < m; i++) {
//		cin >> p[i];
//		end = max(end, p[i]);
//	}
//	sort(p, p + m);
//
//	int result_price = 0, result_count = 0;
//	int cnt;
//	for (int i = 1; i <= end; i++) {
//		cnt = lower_bound(p, p + m, i) - p;
//		cnt = min(n, m - cnt);
//		if (result_price < cnt * i) {
//			result_price = cnt * i;
//			result_count = i;
//		}
//	}
//	cout << result_count << " " << result_price;
//	return 0;
//}