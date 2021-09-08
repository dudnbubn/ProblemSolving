#include <iostream>
using namespace std;

int board[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w, h, minute;
	char cloud;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		minute = -1;
		for (int j = 0; j < w; j++) {
			cin >> cloud;
			if (minute >= 0)	minute++;
			if (cloud == 'c')	minute = 0;
			board[i][j] = minute;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
	return 0;
}