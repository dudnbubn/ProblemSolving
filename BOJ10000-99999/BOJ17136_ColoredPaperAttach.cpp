#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 10
#define MAX_COUNT 25
#define LIMIT 5

int board[SIZE][SIZE];
bool is_visited[SIZE][SIZE];
int result = MAX_COUNT + 1;

int paper_counts[6];
vector<pair<int, int>> ones;
int ones_size;

bool can_cover(int ci, int cj, int size) {
	int ni, nj;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ni = ci + i;
			nj = cj + j;
			if (!board[ni][nj] || is_visited[ni][nj])	return false;
		}
	}
	return true;
}

void set_visited(int ci, int cj, int size, bool status) {
	int ni, nj;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ni = ci + i;
			nj = cj + j;
			is_visited[ni][nj] = status;
		}
	}
}

void back_tracking(int depth) {
	if (depth == ones_size) {
		int sum = 0;
		for (int p = 1; p <= 5; p++)	sum += paper_counts[p];
		result = result < sum ? result : sum;
		return;
	}

	int ci = ones[depth].first;
	int cj = ones[depth].second;
	if (is_visited[ci][cj]) {
		back_tracking(depth + 1);
	}
	else {
		for (int d = 5; d >= 1; d--) {
			if (paper_counts[d] == LIMIT)	continue;
			if ((ci + d > SIZE) || (cj + d > SIZE))	continue;

			if (can_cover(ci, cj, d)) {
				set_visited(ci, cj, d, true);
				paper_counts[d]++;
				back_tracking(depth + 1);
				paper_counts[d]--;
				set_visited(ci, cj, d, false);
			}
		}
	}
}

int main() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> board[i][j];
			if (board[i][j])	ones.push_back({ i, j });
		}
	}

	ones_size = ones.size();
	back_tracking(0);
	cout << (result == MAX_COUNT + 1 ? -1 : result);
	return 0;
}