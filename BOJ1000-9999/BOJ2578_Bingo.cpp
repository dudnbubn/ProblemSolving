#include <iostream>
using namespace std;

int board[6][6] = { 0, };
bool bingo[6][6] = { 0, };
int cnt = 0;

void Check(int i, int j) {
	bool hori = true, vert = true;
	for (int a = 1; a <= 5; a++) {
		hori = (hori && bingo[i][a]);
		vert = (vert && bingo[a][j]);
	}
	if (hori)	cnt++;
	if (vert)	cnt++;
	
	if (i == j) {
		bool flag = true;
		for (int a = 1; a <= 5; a++)
			flag = (flag && bingo[a][a]);
		if (flag)	cnt++;
	}
	if (i + j == 6) {
		bool flag = true;
		for (int a = 1; a <= 5; a++)
			flag = (flag && bingo[a][6 - a]);
		if (flag)	cnt++;
	}
}
int main() {
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			cin >> board[i][j];
	int num;
	int save = 0;
	for (int k = 0; k < 25; k++) {
		cin >> num;
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				if (board[i][j] == num) {
					bingo[i][j] = true;
					Check(i, j);
					if (cnt >= 3 && save == 0)
						save = k + 1;
				}
				
			}
		}
	}
	cout << save;
	return 0;
}