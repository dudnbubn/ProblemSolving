#include <iostream>
#include <algorithm>
using namespace std;

int n, k, l;
pair<int, char> turn[100];

int board[101][101] = { 0, };
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

int main() {
	cin >> n >> k;
	int r, c;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> l;
	int t;
	char d;
	for (int i = 0; i < l; i++)
		cin >> turn[i].first >> turn[i].second;

	board[1][1] = 2;
	int result = 0;
	int head_dir = 0, tail_dir = 0;
	int head_i = 1, head_j = 1, tail_i = 1, tail_j = 1;
	int next_i, next_j;
	int head_turn_index = 0, tail_turn_index = 0;
	int len = 1;
	while (1) {
		result++;
		next_i = head_i + di[head_dir];
		next_j = head_j + dj[head_dir];

		if (next_i < 1 || next_j < 1 || next_i > n || next_j > n || board[next_i][next_j] == 2) {
			cout << result;
			return 0;
		}

		if (board[next_i][next_j] == 1) {
			board[next_i][next_j] = 2;
			len++;
		}
		else {
			board[next_i][next_j] = 2; 
			board[tail_i][tail_j] = 0;
			tail_i += di[tail_dir];
			tail_j += dj[tail_dir];
		}
		head_i = next_i;
		head_j = next_j;
		if (result == turn[head_turn_index].first) {
			if (turn[head_turn_index].second == 'L')
				head_dir = (head_dir + 3) % 4;
			else
				head_dir = (head_dir + 1) % 4;
			head_turn_index++;
		}
		if ((result - len + 1) == turn[tail_turn_index].first) {
			if (turn[tail_turn_index].second == 'L')
				tail_dir = (tail_dir + 3) % 4;
			else
				tail_dir = (tail_dir + 1) % 4;
			tail_turn_index++;
		}
	}
	return 0;
}