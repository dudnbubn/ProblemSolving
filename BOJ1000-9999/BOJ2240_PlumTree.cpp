//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int t, w;
//int arr[1001];
//int result = 0;
//
//void Brute(int cur, int index, int move, int score) {
//	if (index == t) {
//		result = max(result, score);
//		return;
//	}
//
//	if (cur == arr[index]) {
//		Brute(cur, index + 1, move, score + 1);
//	}
//	else {
//		if (move < w)
//			Brute(cur % 2 + 1, index + 1, move + 1, score + 1);
//		Brute(cur, index + 1, move, score);
//	}
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> t >> w;
//	for (int i = 0; i < t; i++)	cin >> arr[i];
//	Brute(1, 0, 0, 0);
//	cout << result;
//	return 0;
//}