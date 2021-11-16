#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, n, m;
int board[101][101] = { 0, };
vector<pair<int, int>> robot;
int dir[101];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	cin >> n >> m;
	robot.push_back({ 0,0 }); 
	
	int x, y;
	char d;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> d;
		robot.push_back({ x,y });
		board[x][y] = i;
		switch (d) {
		case 'N':	dir[i] = 0;	break;
		case 'E':	dir[i] = 1;	break;
		case 'S':	dir[i] = 2;	break;
		case 'W':	dir[i] = 3;	break;
		}
	}
	int num, cnt;
	char cmd;
	int next_x, next_y;
	for (int i = 0; i < m; i++) {
		cin >> num >> cmd >> cnt;
		if (cmd == 'L')		dir[num] = (dir[num] + 4 - (cnt % 4)) % 4;
		else if (cmd == 'R')	dir[num] = (dir[num] + (cnt % 4)) % 4;
		else {
			for (int k = 1; k <= cnt; k++) {
				board[robot[num].first][robot[num].second] = 0;
				next_x = robot[num].first + (k * dx[dir[num]]);
				next_y = robot[num].second + (k * dy[dir[num]]);
				if (next_x < 1 || next_y < 1 || next_x > a || next_y > b) {
					cout << "Robot " << num << " crashes into the wall";
					return 0;
				}
				if (board[next_x][next_y] != 0) {
					cout << "Robot " << num << " crashes into robot " << board[next_x][next_y];
					return 0;
				}
				if (k == cnt) {
					board[next_x][next_y] = num;
					robot[num] = { next_x, next_y };
				}
			}
		}
	}
	cout << "OK";
	return 0;
}