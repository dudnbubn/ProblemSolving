// 킹이 이동할 위치에 돌이 있으면 킹과 돌이 같은 방향으로 움직이는 것이다.
// 킹과 돌이 항상 같은 방향으로 이동하는 것이 아니라는 것을 유의하자.

#include <iostream>
#include <algorithm>
using namespace std;

int df[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int ds[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pair<int, int> king, stone;
	string k, s, cmd;
	int n, index;
	cin >> k >> s >> n;
	king.first = (k[0] - 'A') + 1;	king.second = k[1] - '0';
	stone.first = (s[0] - 'A') + 1;	stone.second = s[1] - '0';
	
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "R")	index = 0;
		else if (cmd == "L")	index = 1;
		else if (cmd == "B")	index = 2;
		else if (cmd == "T")	index = 3;
		else if (cmd == "RT")	index = 4;
		else if (cmd == "LT")	index = 5;
		else if (cmd == "RB")	index = 6;
		else if (cmd == "LB")	index = 7;

		if (king.first + df[index] <= 0 || king.first + df[index] > 8)	continue;
		if (king.second + ds[index] <= 0 || king.second + ds[index] > 8)	continue;

		king.first += df[index];	king.second += ds[index];
		if (king == stone) {
			if (stone.first + df[index] <= 0 || stone.first + df[index] > 8) {
				king.first -= df[index];	king.second -= ds[index];
				continue;
			}
			if (stone.second + ds[index] <= 0 || stone.second + ds[index] > 8) {
				king.first -= df[index];	king.second -= ds[index];
				continue;
			}
			stone.first += df[index];	stone.second += ds[index];
		}
	}
	cout << (char)(king.first + 'A' - 1) << king.second << "\n";
	cout << (char)(stone.first + 'A' - 1) << stone.second;
	return 0;
}