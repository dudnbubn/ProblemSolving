//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int n;
//int S[21][21] = { 0, };
//bool isUsed[21] = { 0, };
//int teamLink[21] = { 0, };
//int minimum = 1000000000;
//
//void Combination(int k, int prev, int stat) {
//	if (k > (n / 2))
//		return;
//	if (k >= 2 && k <= (n / 2)) {
//		for (int i = 0; i < k - 1; i++) {
//			stat += (S[teamLink[i]][prev] + S[prev][teamLink[i]]);
//		}
//		vector<int> teamStart;
//		for (int i = 1; i <= n; i++) {
//			if (!isUsed[i])
//				teamStart.push_back(i);
//		}
//		int scoreStart = 0;
//		for (int i = 0; i < teamStart.size() - 1; i++) {
//			for (int j = i + 1; j < teamStart.size(); j++) {
//				scoreStart += (S[teamStart[i]][teamStart[j]] + S[teamStart[j]][teamStart[i]]);
// 			}
//		}
//		minimum = min(minimum, abs(stat - scoreStart));
//	}
//	for (int i = prev + 1; i <= n; i++) {
//		if (!isUsed[i]) {
//			isUsed[i] = true;
//			teamLink[k] = i;
//			Combination(k + 1, i, stat);
//			isUsed[i] = false;
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			cin >> S[i][j];
//	}
//	Combination(0, 0, 0);
//	cout << minimum;
//	return 0;
//}