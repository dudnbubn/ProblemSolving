//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int N, M;
//char board[50][50];
//bool visited[50][50][1 << 6];
//int di[4] = { -1, 0, 1, 0 };
//int dj[4] = { 0, 1, 0, -1 };
//queue<pair<pair<int, int>, int>> q;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N >> M;
//	string input;
//	int ci, cj, key;
//	for (int i = 0; i < N; i++) {
//		cin >> input;
//		for (int j = 0; j < M; j++) {
//			board[i][j] = input[j];
//			if (board[i][j] == '0') {
//				ci = i;
//				cj = j;
//			}
//		}
//	}
//	
//	q.push({ {ci, cj}, 0 });
//	visited[ci][cj][0] = true;
//
//	pair<pair<int, int>, int> cur;
//	int ni, nj, result = -1, qsz, level = -1;
//	while (!q.empty()) {
//		level++;
//		qsz = q.size();
//		for (int sz = 0; sz < qsz; sz++) {
//			cur = q.front();
//			q.pop();
//			ci = cur.first.first;
//			cj = cur.first.second;
//			key = cur.second;
//
//			if (board[ci][cj] == '1') {
//				result = level;
//				break;
//			}
//
//			for (int d = 0; d < 4; d++) {
//				ni = ci + di[d];
//				nj = cj + dj[d];
//				if (ni < 0 || nj < 0 || ni >= N || nj >= M || board[ni][nj] == '#' || visited[ni][nj][key])
//					continue;
//
//				if ('a' <= board[ni][nj] && board[ni][nj] <= 'f') {
//					visited[ni][nj][key | (1 << (board[ni][nj] - 'a'))] = true;
//					q.push({ {ni, nj}, key | (1 << (board[ni][nj] - 'a')) });
//				}
//				else if ('A' <= board[ni][nj] && board[ni][nj] <= 'F') {
//					if ((key & (1 << board[ni][nj] - 'A')) == (1 << board[ni][nj] - 'A')) {
//						visited[ni][nj][key] = true;
//						q.push({ {ni, nj}, key });
//					}
//				}
//				else {
//					visited[ni][nj][key] = true;
//					q.push({ {ni, nj}, key });
//				}
//			}
//		}
//		if (result != -1)	break;
//	}
//	cout << result;
//	return 0;
//}