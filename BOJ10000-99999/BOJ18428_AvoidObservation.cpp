#include <iostream>
#include <algorithm>
using namespace std;

int n, t = 0;
pair<int, int> T[10];
char hallway[10][10];
int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

bool check() {
	int cur_i, cur_j, next_i, next_j;
	for (int i = 0; i < t; i++) {
		cur_i = T[i].first;
		cur_j = T[i].second;
		for (int k = 0; k < 4; k++) {
			int len = 1;
			while (1) {
				next_i = cur_i + (len * di[k]);
				next_j = cur_j + (len * dj[k]);
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
					break;
				if (hallway[next_i][next_j] == 'O' || hallway[next_i][next_j] == 'T')
					break;
				if (hallway[next_i][next_j] == 'S')
					return false;
				len++;
			}
		}
	}
	return true;
}

void Brute(int k, int r, int c) {
	if (k == 3) {
		if (check()) {
			cout << "YES";
			exit(0);
		}
		else	
			return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((r < i) || ((r == i) && (c < j))) {
				if (hallway[i][j] == 'X') {
					hallway[i][j] = 'O';
					Brute(k + 1, i, j);
					hallway[i][j] = 'X';
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> hallway[i][j];
			if (hallway[i][j] == 'T') {
				T[t] = { i,j };
				t++;
			}
		}
	}
	Brute(0, 1, 0);
	cout << "NO";
	return 0;
}