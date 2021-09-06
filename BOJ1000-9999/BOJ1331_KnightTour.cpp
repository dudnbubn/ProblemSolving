#include <iostream>
using namespace std;

bool visited[6][6] = { 0, };

bool canMove(int prev_x, int prev_y, int cur_x, int cur_y) {
	if (abs(prev_x - cur_x) == 2 && abs(prev_y - cur_y) == 1)	return true;
	if (abs(prev_x - cur_x) == 1 && abs(prev_y - cur_y) == 2)	return true;
	return false;
}

int main() {
	char x;
	int y;
	bool valid = false;
	cin >> x >> y;
	int start_x = x - 'A', start_y = y - 1;
	int prev_x = start_x, prev_y = start_y;
	int cur_x, cur_y;
	for (int i = 1; i < 36; i++) {
		cin >> x >> y;
		cur_x = x - 'A';
		cur_y = y - 1;
		if (visited[cur_x][cur_y] || !canMove(prev_x, prev_y, cur_x, cur_y))	break;
		if (i == 35) {
			if (canMove(cur_x, cur_y, start_x, start_y)) valid = true;
			else	break;
		}
		visited[cur_x][cur_y] = true;
		prev_x = cur_x;
		prev_y = cur_y;
	}
	
	if (valid)	cout << "Valid";
	else	cout << "Invalid";

	return 0;
}