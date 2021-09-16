#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool adj = false;
char farm[505][505] = { 0, };
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0,1,0,-1 };
vector<pair<int, int>> wolves;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> farm[i][j];
			if (farm[i][j] == '.')	farm[i][j] = 'D';
			else if (farm[i][j] == 'W')	wolves.push_back({ i,j });
		}
	}
	for (pair<int, int> w : wolves) {
		for (int i = 0; i < 4; i++) {
			if (farm[w.first + dr[i]][w.second + dc[i]] == 'S') {
				adj = true;
				break;
			}
		}
		if (adj)	break;
	}
	if (adj)	cout << 0;
	else {
		cout << 1 << "\n";
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++)
				cout << farm[i][j];
			cout << "\n";
		}
	}
	return 0;
}