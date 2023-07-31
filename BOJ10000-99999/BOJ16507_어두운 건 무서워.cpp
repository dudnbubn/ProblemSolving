#include <iostream>

using namespace std;

int subsum[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C, Q;
	cin >> R >> C >> Q;

	int input;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cin >> input;
			subsum[r][c] = subsum[r - 1][c] + subsum[r][c - 1] - subsum[r - 1][c - 1] + input;
		}
	}

	int r1, c1, r2, c2;
	int avg;
	while (Q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		avg = (subsum[r2][c2] - subsum[r1 - 1][c2] - subsum[r2][c1 - 1] + subsum[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1));
		cout << avg << "\n";
	}

}