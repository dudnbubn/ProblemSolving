#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> cctv;
int n, m;
int office[9][9];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
cctv obs[8];
int obs_cnt = 0;
int min_size = 64;

void Brute(int k) {
	if (k == obs_cnt) {
		int sz = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (office[i][j] == 0)
					sz++;
		min_size = min(min_size, sz);
	}
	int cur_i = obs[k].first.first;
	int cur_j = obs[k].first.second;
	int next_i, next_j;
	if (obs[k].second == 1) {
		for (int i = 0; i < 4; i++) {
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			Brute(k + 1);
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
		}
	}
	else if (obs[k].second == 2) {
		for (int i = 0; i < 2; i++) {
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i + 2]);
				next_j = cur_j + (r * dj[i + 2]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			Brute(k + 1);
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i + 2]);
				next_j = cur_j + (r * dj[i + 2]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
		}
	}
	else if (obs[k].second == 3) {
		for (int i = 0; i < 4; i++) {
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[(i + 1) % 4]);
				next_j = cur_j + (r * dj[(i + 1) % 4]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			Brute(k + 1);
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[(i + 1) % 4]);
				next_j = cur_j + (r * dj[(i + 1) % 4]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
		}
	}
	else if (obs[k].second == 4) {
		for (int i = 0; i < 4; i++) {
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[(i + 1) % 4]);
				next_j = cur_j + (r * dj[(i + 1) % 4]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[(i + 2) % 4]);
				next_j = cur_j + (r * dj[(i + 2) % 4]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
			Brute(k + 1);
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[(i + 1) % 4]);
				next_j = cur_j + (r * dj[(i + 1) % 4]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[(i + 2) % 4]);
				next_j = cur_j + (r * dj[(i + 2) % 4]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
		}
	}
	else if (obs[k].second == 5) {
		for (int i = 0; i < 4; i++) {
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] <= 0)
					office[next_i][next_j]--;
			}
		}
		Brute(k + 1);
		for (int i = 0; i < 4; i++) {
			for (int r = 1; r < 8; r++) {
				next_i = cur_i + (r * di[i]);
				next_j = cur_j + (r * dj[i]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || (office[next_i][next_j] == 6))
					break;
				if (office[next_i][next_j] < 0)
					office[next_i][next_j]++;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6) {
				obs[obs_cnt] = { {i,j} ,office[i][j] };
				obs_cnt++;
			}
		}
	}
	Brute(0);
	cout << min_size;
	return 0;
}