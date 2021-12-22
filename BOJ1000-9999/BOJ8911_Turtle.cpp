#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int control_program(string s) {
	int x = 0, y = 0, dir = 0;
	int x_high = 0, x_low = 0;
	int y_high = 0, y_low = 0;

	for (int i = 0; i < s.size(); i++) {
		char cmd = s[i];
		if (cmd == 'F') {
			x = x + dx[dir];
			y = y + dy[dir];
			x_high = max(x_high, x);
			x_low = min(x_low, x);
			y_high = max(y_high, y);
			y_low = min(y_low, y);
		}
		else if (cmd == 'B') {
			x = x - dx[dir];
			y = y - dy[dir];
			x_high = max(x_high, x);
			x_low = min(x_low, x);
			y_high = max(y_high, y);
			y_low = min(y_low, y);
		}
		else if (cmd == 'L')
			dir = (dir + 3) % 4;
		else if (cmd == 'R')
			dir = (dir + 1) % 4;
	}
	return (x_high - x_low) * (y_high - y_low);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		cout << control_program(cmd) << "\n";
	}
	return 0;
}