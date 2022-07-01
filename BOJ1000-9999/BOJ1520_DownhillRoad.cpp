//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int M, N;
//int board[502][502];
//int dp[502][502];
//bool visited[502][502];
//int di[4] = { -1, 0, 1, 0 };
//int dj[4] = { 0 ,1, 0 ,-1 };
//
//struct compare {
//	bool operator()(pair<int, int> a, pair<int, int> b) {
//		if (board[a.first][a.second] == board[b.first][b.second])
//			return a.first < b.first;
//		return board[a.first][a.second] < board[b.first][b.second];
//	}
//};
//priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
//
//int main() {
//	cin >> M >> N;
//	for (int i = 1; i <= M; i++)
//		for (int j = 1; j <= N; j++)
//			cin >> board[i][j];
//	
//	dp[1][1] = 1;
//	visited[1][1] = true;
//	
//	pq.push({ 1, 1 });
//	pair<int, int> cur;
//	int next_i, next_j;
//	while (!pq.empty()) {
//		cur = pq.top();
//		pq.pop();
//
//		for (int k = 0; k < 4; k++) {
//			next_i = cur.first + di[k];
//			next_j = cur.second + dj[k];
//
//			if (1 <= next_i && next_i <= M && 1 <= next_j && next_j <= N) {
//				if(board[cur.first][cur.second] < board[next_i][next_j])
//					dp[cur.first][cur.second] += dp[next_i][next_j];
//				else if (!visited[next_i][next_j] && (board[cur.first][cur.second] > board[next_i][next_j])) {
//					visited[next_i][next_j] = true;
//					pq.push({ next_i, next_j });
//				}
//			}
//		}
//	}
//
//	cout << dp[M][N];
//	return 0;
//}