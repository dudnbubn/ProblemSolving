//// max({a, b, c}) (3개 이상의 인자) 를 컴파일러가 알아먹지 못한 것 같다..
//// -> max(a, max(b, c)) 의 형태으로 바꿔주니 맞았다.
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n, m;
//int board[505][505] = { 0, };
//
//int Check(int i, int j, int dir, int len) {
//	int sum = 0;
//	if (len == 2) {
//		if (dir == 0) {
//			sum = board[i][j] + board[i][j + 1];
//			sum += max((board[i + 1][j - 1] + board[i + 1][j]), max((board[i + 1][j] + board[i + 1][j + 1]), (board[i + 1][j + 1] + board[i + 1][j + 2] )));
//		}
//		else {
//			sum = board[i][j] + board[i + 1][j];
//			sum += max((board[i - 1][j + 1] + board[i][j + 1]), max((board[i][j + 1] + board[i + 1][j + 1]), (board[i + 1][j + 1] + board[i + 2][j + 1] )));
//		}
//	}
//	else {
//		if (dir == 0) {
//			sum = board[i][j] + board[i][j + 1] + board[i][j + 2];
//			sum += max(board[i - 1][j], max(board[i - 1][j + 1], max(board[i - 1][j + 2], max(board[i][j + 3], max(board[i + 1][j], max(board[i + 1][j + 1], board[i + 1][j + 2]))))));
//		}
//		else {
//			sum = board[i][j] + board[i + 1][j] + board[i + 2][j];
//			sum += max(board[i][j - 1], max(board[i][j + 1], max(board[i + 1][j - 1], max(board[i + 1][j + 1], max(board[i + 2][j - 1], max(board[i + 2][j + 1], board[i + 3][j]))))));
//		}
//	}
//	//cout << "Check(" << i << ", " << j << ", " << dir << ", " << len << ") : " << sum << "\n";
//	return sum;
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			cin >> board[i][j];
//	}
//	int maximum = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			maximum = max( maximum, max(Check(i, j, 0, 2), Check(i,j,1,2) ));
//
//			maximum = max(maximum, Check(i, j, 0, 3));
//
//			maximum = max(maximum, Check(i, j, 1, 3));
//		}
//	}
//	cout << maximum;
//	return 0;
//}