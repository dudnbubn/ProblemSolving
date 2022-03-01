#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int board[50][50];
bool visited[50][50];
int di[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dj[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
pair<int, int> cloud[2500];
int cnt[2500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	cloud[0] = { n - 2, 0 };
	cloud[1] = { n - 2, 1 };
	cloud[2] = { n - 1, 0 };
	cloud[3] = { n - 1, 1 };
	
	int d, s, index = 4;
	int next_i, next_j;
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		for (int i = 0; i < index; i++) {
			cloud[i].first = (cloud[i].first + (n * 50) + (di[d] * s)) % n;
			cloud[i].second = (cloud[i].second + (n * 50) + (dj[d] * s)) % n;
			visited[cloud[i].first][cloud[i].second] = true;
			board[cloud[i].first][cloud[i].second]++;
			cnt[i] = 0;
		}
		for (int i = 0; i < index; i++) {
			for (int j = 2; j <= 8; j += 2) {
				next_i = cloud[i].first + di[j];
				next_j = cloud[i].second + dj[j];
				if (next_i < 0 || next_j < 0 || next_i >= n || next_j >= n)	continue;
				if (board[next_i][next_j])
					cnt[i]++;
			}
		}

		for (int i = 0; i < index; i++) {
			board[cloud[i].first][cloud[i].second] += cnt[i];
		}

		index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) {
					visited[i][j] = false;
					continue;
				}
				if (board[i][j] > 1) {
					board[i][j] -= 2;
					cloud[index] = { i, j };
					index++;
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result += board[i][j];
	cout << result;
	return 0;
}