//#include <iostream>
//#include <queue>
//#include <set>
//
//using namespace std;
//
//int n, m;
//int board[1001][1001];
//int index = 1;
//int cnt[555555];
//int di[4] = { -1, 0, 1, 0 };
//int dj[4] = { 0, 1, 0, -1 };
//
//void BFS(int i, int j) {
//	index++;
//	queue<pair<int, int>> q;
//	pair<int, int> cur;
//	int next_i, next_j;
//	board[i][j] = index;
//	q.push({ i,j });
//	while (!q.empty()) {
//		cur = q.front();
//		q.pop();
//		cnt[index]++;
//		for (int k = 0; k < 4; k++) {
//			next_i = cur.first + di[k];
//			next_j = cur.second + dj[k];
//			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
//				continue;
//			if (board[next_i][next_j] == 0) {
//				board[next_i][next_j] = index;
//				q.push({ next_i, next_j });
//			}
//		}
//	}
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> n >> m;
//	char input;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> input;
//			board[i][j] = input - '0';
//		}
//	}
//	set<int> adj;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			if (board[i][j] == 0)
//				BFS(i, j);
//
//	int next_i, next_j, result;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (board[i][j] == 1) {
//				result = 1;
//				adj = {};
//				for (int k = 0; k < 4; k++) {
//					next_i = i + di[k];
//					next_j = j + dj[k];
//					if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
//						continue;
//					if (adj.find(board[next_i][next_j]) == adj.end()) {
//						result += cnt[board[next_i][next_j]];
//						adj.insert(board[next_i][next_j]);
//					}
//				}
//				cout << result % 10;
//			}
//			else
//				cout << 0;
//		}
//		cout << "\n";
//	}
//	return 0;
//}