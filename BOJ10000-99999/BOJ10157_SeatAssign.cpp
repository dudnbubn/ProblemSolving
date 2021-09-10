#include <iostream>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
bool assigned[1002][1002] = { 0, };

int main() {
	int c, r, k, dir = 0;
	int x = 1, y = 0, temp_x, temp_y;
	cin >> c >> r >> k;
	if (k > c * r)	cout << 0;
	else {
		for (int i = 1; i <= c * r; i++) {
			x += dx[dir];
			y += dy[dir];
			assigned[x][y] = true;
			if (i == k) {
				cout << x << " " << y;
				return 0;
			}
			temp_x = x + dx[dir];	temp_y = y + dy[dir];
			if (assigned[temp_x][temp_y] || temp_x < 1 || temp_x > c || temp_y < 1 || temp_y > r)
				dir = (dir + 1) % 4;
		}
	}
	return 0;
}