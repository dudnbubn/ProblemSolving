#include <iostream>
#include <vector>

using namespace std;

int N, x, y, d, g;
bool board[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dir[4][2] = { {1, 3}, {2, 0}, {3, 1}, {0, 2} };

vector<int> curve[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	curve[1].push_back(0);
	for (int i = 2; i <= 10; i++) {
		curve[i].push_back(0);
		for (int j = i - 1; j >= 1; j--) {
			for (int k = curve[j].size() - 1; k >= 0; k--) {
				curve[i].push_back((curve[j][k] + 1) % 2);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
	
		board[y][x] = true;
		y += dy[d];
		x += dx[d];
		board[y][x] = true;
		for (int i = 1; i <= g; i++) {
			for (int j = 0; j < curve[i].size(); j++) {
				d = dir[d][curve[i][j]];
				y += dy[d];
				x += dx[d];
				if (y < 0 || x < 0 || y > 100 || x > 100)
					continue;
				board[y][x] = true;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
				result++;
		}
	}
	cout << result;

	return 0;
}