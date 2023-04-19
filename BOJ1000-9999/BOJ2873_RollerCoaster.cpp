#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int R, C;
int board[1000][1000];
queue<char> from_front;
stack<char> from_back;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> board[r][c];
		}
	}
	
	if (R % 2 == 0 && C % 2 == 0) {
		int minimum = 1001;
		int min_r, min_c;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if ((r + c) & 1) {
					if (board[r][c] < minimum) {
						minimum = board[r][c];
						min_r = r;
						min_c = c;
					}
				}
			}
		}
		int si = 0, sj = 0;
		for (int r = 1; r < min_r; r += 2) {
			for (int i = 1; i < C; i++)	from_front.push('R');
			from_front.push('D');
			for (int i = 1; i < C; i++)	from_front.push('L');
			from_front.push('D');
			si = r + 1;
		}
		for (int c = 1; c < min_c; c += 2) {
			from_front.push('D');
			from_front.push('R');
			from_front.push('U');
			from_front.push('R');
			sj = c + 1;
		}
		
		int ei = R - 1, ej = C - 1;
		for (int r = R - 2; r > min_r; r -= 2) {
			for (int i = 1; i < C; i++)	from_back.push('R');
			from_back.push('D');
			for (int i = 1; i < C; i++)	from_back.push('L');
			from_back.push('D');
			ei = r - 1;
		}
		for (int c = C - 2; c > min_c; c -= 2) {
			from_back.push('D');
			from_back.push('R');
			from_back.push('U');
			from_back.push('R');
			ej = c - 1;
		}

		if (si == min_r) {
			from_front.push('D');
			from_front.push('R');
		}
		else {
			from_front.push('R');
			from_front.push('D');
		}

		while (!from_front.empty()) {
			cout << from_front.front();
			from_front.pop();
		}
		while (!from_back.empty()) {
			cout << from_back.top();
			from_back.pop();
		}
	}
	else {
		if (R & 1) {
			for (int r = 1; r <= R; r++) {
				for (int c = 1; c < C; c++) {
					if (r & 1)	cout << "R";
					else	cout << "L";
				}
				if (r < R)	cout << "D";
			}
		}
		else {
			for (int c = 1; c <= C; c++) {
				for (int r = 1; r < R; r++) {
					if (c & 1)	cout << "D";
					else	cout << "U";
				}
				if(c < C) cout << "R";
			}
		}
	}
	return 0;
}