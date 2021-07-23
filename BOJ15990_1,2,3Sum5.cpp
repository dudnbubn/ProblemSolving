//#include <iostream>
//using namespace std;
//
//long long case_cnt[100001][3] = { 0, };
//
//long long Count(int n, int index) {
//	if (case_cnt[n][index] != 0 || n <= 3)
//		return case_cnt[n][index];
//
//	if (index == 2)	return case_cnt[n][2] = (Count(n - 3, 0) + Count(n - 3, 1)) % 1000000009;
//	else if (index == 1)	return case_cnt[n][1] = (Count(n - 2, 0) + Count(n - 2, 2)) % 1000000009;
//	else if (index == 0)	return case_cnt[n][0] = (Count(n - 1, 1) + Count(n - 1, 2)) % 1000000009;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	case_cnt[1][0] = 1;
//	case_cnt[1][1] = 0;
//	case_cnt[1][2] = 0;
//	case_cnt[2][0] = 0;
//	case_cnt[2][1] = 1;
//	case_cnt[2][2] = 0;
//	case_cnt[3][0] = 1;
//	case_cnt[3][1] = 1;
//	case_cnt[3][2] = 1;
//
//	int testcase, num;
//	cin >> testcase;
//	while (testcase--) {
//		cin >> num;
//		cout << (Count(num, 0) + Count(num, 1) + Count(num, 2)) % 1000000009 << "\n";
//	}
//
//	
//	return 0;
//}