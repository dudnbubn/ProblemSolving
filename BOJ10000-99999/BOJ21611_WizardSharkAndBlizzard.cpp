#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 49

int N, M;
int board[MAX_N + 1][MAX_N + 1];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int explosion_count[4];

int get_d(int d) {
	switch (d) {
	case 1: return 0;
	case 2: return 2;
	case 3: return 3;
	case 4: return 1;
	}
}

void blizzard(int d, int s) {
	d = get_d(d);
	
	int ci = (N + 1) / 2;
	int cj = ci;
	for (int i = 1; i <= s; i++) {
		ci += di[d];
		cj += dj[d];

		board[ci][cj] = 0;
	}
}

void explosion(vector<pair<int, int>> &beads) {
	beads = {};

	int ci = (N + 1) / 2;
	int cj = ci;

	int limit = 1;
	int length = 0;
	bool check = false;
	int d = 3;

	int bead_number = 0, bead_count = 0;
	while (true) {
		ci += di[d];
		cj += dj[d];

		if (++length == limit) {
			if (length == N)	break;
			length = 0;
			d = (d + 3) % 4;
			if (check)	limit++;
			check = !check;
		}

		if (!board[ci][cj])	continue;
		
		if (board[ci][cj] == bead_number) {
			bead_count++;
		}
		else {
			beads.push_back({ bead_number, bead_count });
			bead_number = board[ci][cj];
			bead_count = 1;
		}
	}
	beads.push_back({ bead_number, bead_count });

	vector<pair<int, int>> save;

	bool is_exploded = true;
	while (is_exploded) {
		save = {};
		is_exploded = false;
		
		int beads_size = beads.size();
		for (int i = 0; i < beads_size; i++) {
			bead_number = beads[i].first;
			bead_count = beads[i].second;
			if (bead_count > 3) {
				is_exploded = true;
				explosion_count[bead_number] += bead_count;
			}
			else {
				if (save.empty() || save[save.size() - 1].first != bead_number)
					save.push_back({ bead_number, bead_count });
				else
					save[save.size() - 1].second += bead_count;
			}
		}

		beads = save;
	}
}

void change(vector<pair<int, int>> &beads) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] = 0;

	int ci = (N + 1) / 2;
	int cj = ci;

	int limit = 1;
	int length = 0;
	bool check = false;
	int d = 3;
	int index = 1;
	bool first_turn = false;

	int beads_size = beads.size();
	while (index < beads_size) {
		ci += di[d];
		cj += dj[d];

		if (++length == limit) {
			if (length == N)	break;
			length = 0;
			d = (d + 3) % 4;
			if (check)	limit++;
			check = !check;
		}

		if (first_turn) {
			first_turn = false;
			board[ci][cj] = beads[index].first;
			index++;
		}
		else {
			first_turn = true;
			board[ci][cj] = beads[index].second;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	int d, s;
	vector<pair<int, int>> beads;
	for (int m = 0; m < M; m++) {
		cin >> d >> s;
		blizzard(d, s);
		explosion(beads);
		change(beads);
	}

	int result = explosion_count[1] + explosion_count[2] * 2 + explosion_count[3] * 3;
	cout << result;
	return 0;
}