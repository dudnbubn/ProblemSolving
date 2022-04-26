//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//char board[52][52];
//bool visited[52][52][2];
//
//pair<pair<int, int>, int> Move(pair<pair<int, int>, int> cur, int cmd) {
//	int i = cur.first.first;
//	int j = cur.first.second;
//	int d = cur.second;
//	switch (cmd) {
//	case 0:
//		if (d) {
//			if (i != 1 && board[i - 1][j - 1] != '1' && board[i - 1][j] != '1' && board[i - 1][j + 1] != '1')
//				return { {i - 1, j}, d };
//		}
//		else {
//			if (i > 2 && board[i - 2][j] != '1')
//				return { {i - 1, j}, d };
//		}
//		break;
//	case 1:
//		if (d) {
//			if (i != n && board[i + 1][j - 1] != '1' && board[i + 1][j] != '1' && board[i + 1][j + 1] != '1')
//				return { {i + 1, j}, d };
//		}
//		else {
//			if (i < n - 1 && board[i + 2][j] != '1')
//				return { {i + 1, j}, d };
//		}
//		break;
//	case 2:
//		if (d) {
//			if (j > 2 && board[i][j - 2] != '1')
//				return { {i, j - 1}, d };
//		}
//		else {
//			if (j != 1 && board[i - 1][j - 1] != '1' && board[i][j - 1] != '1' && board[i + 1][j - 1] != '1')
//				return { {i, j - 1}, d };
//		}
//		break;
//	case 3:
//		if (d) {
//			if (j < n - 1 && board[i][j + 2] != '1')
//				return { {i, j + 1}, d };
//		}
//		else {
//			if (j != n && board[i - 1][j + 1] != '1' && board[i][j + 1] != '1' && board[i + 1][j + 1] != '1')
//				return { {i, j + 1}, d };
//		}
//		break;
//	case 4:
//		if (i < 2 || j < 2 || i>n - 1 || j > n - 1)	return { {0, 0}, 0 };
//		for (int a = i - 1; a <= i + 1; a++)
//			for (int b = j - 1; b <= j + 1; b++)
//				if (board[a][b] == '1')	return { {0, 0}, 0 };
//		return { {i,j}, (d + 1) % 2 };
//	}
//	return { {0, 0}, 0 };
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cin >> board[i][j];
//
//	int b_i, b_j, b_d, e_i, e_j, e_d;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (board[i][j] == 'B') {
//				if (board[i - 1][j] == 'B' && board[i + 1][j] == 'B') {
//					b_i = i;	b_j = j;	b_d = 0;
//				}
//				else if (board[i][j - 1] == 'B' && board[i][j + 1] == 'B') {
//					b_i = i;	b_j = j;	b_d = 1;
//				}
//			}
//			else if(board[i][j] == 'E'){
//				if (board[i - 1][j] == 'E' && board[i + 1][j] == 'E') {
//					e_i = i;	e_j = j;	e_d = 0;
//				}
//				else if (board[i][j - 1] == 'E' && board[i][j + 1] == 'E') {
//					e_i = i;	e_j = j;	e_d = 1;
//				}
//			}
//		}
//	}
//
//	queue<pair<pair<int, int>, int>> q;
//	q.push({ {b_i,b_j},b_d });
//	visited[0][0][0] = true;
//	visited[b_i][b_j][b_d] = true;
//
//	int result = -1, qsz;
//	pair<pair<int, int>, int> cur, next, end;
//	end = make_pair(make_pair(e_i, e_j), e_d);
//	while (!q.empty()) {
//		result++;
//		qsz = q.size();
//		for (int sz = 0; sz < qsz; sz++) {
//			cur = q.front();
//			q.pop();
//
//			if (cur == end) {
//				std::cout << result;
//				return 0;
//			}
//			for (int k = 0; k < 5; k++) {
//				next = Move(cur, k);
//				if (!visited[next.first.first][next.first.second][next.second]) {
//					visited[next.first.first][next.first.second][next.second] = true;
//					q.push(next);
//				}
//			}
//		}
//	}
//	std::cout << 0;
//	return 0;
//}