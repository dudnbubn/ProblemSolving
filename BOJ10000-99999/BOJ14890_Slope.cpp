#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int board[101][101];

bool check(int r, int c, int dir) {
	int cur_i = r, cur_j = c;
	vector<pair<int, int>> v;
	v.push_back({ board[cur_i][cur_j], 1 });
	for (int k = 1; k < N; k++) {
		cur_i = r + k * dir;
		cur_j = c + k * ((dir + 1) % 2);
		switch (board[cur_i][cur_j] - board[cur_i - dir][cur_j - (dir + 1) % 2]) {
		case 0:
			v[v.size() - 1].second++;	break;
		case 1:
		case -1:
			v.push_back({ board[cur_i][cur_j], 1 });	break;
		default:
			return false;
		}
	}
	
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i].first < v[i + 1].first) {
			if (v[i].second >= L) continue;
			else	return false;
		}
		else if (v[i].first > v[i + 1].first) {
			if (v[i + 1].second >= L)	v[i + 1].second -= L;
			else	return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	
	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (check(i, 1, 0)) result++;
		if (check(1, i, 1)) result++;
	}
	cout << result;
	return 0;
}