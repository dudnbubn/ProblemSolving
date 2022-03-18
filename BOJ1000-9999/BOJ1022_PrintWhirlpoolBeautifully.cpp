#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int map[101][101];
int r1, c1, r2, c2;
int di[4] = { 0, -1, 0, 1 };
int dj[4] = { 1, 0, -1, 0 };

bool check(int i, int j) {
	if ((r1 <= i && i <= r2) && (c1 <= j && j <= c2))
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r1 >> c1 >> r2 >> c2;
	int break_r = max(abs(r1), abs(r2)), break_c = max(abs(c1), abs(c2));
	int num = 2, i = 0, j = 0, len = 1, dir = 0, temp = 0;
	if (check(0, 0))	map[0 - r1][0 - c1] = 1;
	bool flag = false;
	while (num <= 110000000) {
		if (i > break_r && j > break_c)	break;
		i += di[dir];	j += dj[dir];

		if (check(i, j))
			map[i - r1][j - c1] = num;
		num++;
		temp++;
		if (temp == len) {
			if (!flag)	flag = true;
			else {
				flag = false;
				len++;
			}
			dir = (dir + 1) % 4;
			temp = 0;
		}
	}
	
	int maxlen = 0;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			len = 0;	temp = map[i][j];
			while (temp) {
				len++;
				temp /= 10;
			}
			maxlen = maxlen > len ? maxlen : len;
		}
	}
	
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			cout.width(maxlen);
			cout.fill(' ');
			cout << map[i][j];
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
	
}