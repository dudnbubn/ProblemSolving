//// 문제를 정확히 이해하지 못하고 사탕을 교환한 후 행이나 열에서 사탕의 최대 개수를 구함.
//// 하지만 문제에서 요구한 것은 가장 긴 '연속 부분'의 사탕임을 잘 짚었어야 함.
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n;
//char board[51][51];
//int maximum = 0;
//
//void Swap(int i1, int j1, int i2, int j2) {
//	char temp = board[i1][j1];
//	board[i1][j1] = board[i2][j2];
//	board[i2][j2] = temp;
//}
//
//int Count(int i, int j, int dir) {
//	char cur = ' ';
//	int cnt = 0;
//	int temp = 0;
//	if (dir == 0) {
//		for (int c = 1; c <= n; c++) {
//			if (board[i][c] != cur) {
//				if (cnt < temp)
//					cnt = temp;
//				temp = 0;
//				cur = board[i][c];
//			}
//			temp++;
//		}
//		if (cnt < temp)
//			cnt = temp;
//	}
//	else {
//		for (int r = 1; r <= n; r++) {
//			if (board[r][j] != cur) {
//				if (cnt < temp)
//					cnt = temp;
//				temp = 0;
//				cur = board[r][j];
//			}
//			temp++;
//		}
//		if (cnt < temp)
//			cnt = temp;
//	}
//	return cnt;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			cin >> board[i][j];
//	}
//	for (int i = 1, j = 1; i <= n; i++, j++) {
//		int cnt = Count(i, j, 0);
//		if (maximum < cnt)
//			maximum = cnt;
//		cnt = Count(i, j, 1);
//		if (maximum < cnt)
//			maximum = cnt;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (j < n) {
//				if (board[i][j] == board[i][j + 1])
//					continue;
//				Swap(i, j, i, j + 1);
//				int cnt = max(Count(i, j, 0), max(Count(i, j, 1), Count(i, j + 1, 1)));
//				if (maximum < cnt)
//					maximum = cnt;
//				Swap(i, j, i, j + 1);
//			}
//			if (i < n) {
//				if (board[i][j] == board[i + 1][j])
//					continue;
//				Swap(i, j, i + 1, j);
//				int cnt = max(Count(i, j, 1), max(Count(i, j, 0), Count(i + 1, j, 0)));
//				if (maximum < cnt)
//					maximum = cnt;
//				Swap(i, j, i + 1, j);
//			}
//		}
//	}
//	cout << maximum;
//	return 0;
//}