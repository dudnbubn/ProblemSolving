#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int r, c, n;
char board[201][201];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };
set<pair<int, int>> temp;
set<pair<int, int>> broken;
set<pair<int, int>>::iterator iter;
bool flag = false;

void setBomb() {
	if (flag) {
		//cout << "q1 에..\n";
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (board[i][j] == '.') {
					board[i][j] = 'O';
					q1.push({ i,j });
					//cout << "\t{ " << i << ", " << j << " } push\n";
				}
			}
		}
	}
	else {
		//cout << "q2 에..\n";
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (board[i][j] == '.') {
					board[i][j] = 'O';
					q2.push({ i,j });
					//cout << "\t{ " << i << ", " << j << " } push\n";
				}
			}
		}
	}
	flag = !flag;
}

void Timeout() {
	pair<int, int> cur;
	int next_i, next_j;
	temp.clear();
	if (flag) {
		//cout << "q1 에서..\n";
		while (!q1.empty()) {
			cur = q1.front();
			q1.pop();
			if (broken.find(cur) != broken.end())	continue;
			if (board[cur.first][cur.second] == '.')	continue;
			temp.insert(cur);
			//cout << "\t" << cur.first << ", " << cur.second << " bomb \n";
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > r || next_j > c)
					continue;
				temp.insert({ next_i,next_j });
			}
		}
		broken.clear();
		for (iter = temp.begin(); iter != temp.end(); iter++) {
			if (board[iter->first][iter->second] == 'O')
				broken.insert(*iter);
			board[iter->first][iter->second] = '.';
		}
	}
	else {
		//cout << "q2 에서..\n";
		while (!q2.empty()) {
			cur = q2.front();
			q2.pop();
			if (broken.find(cur) != broken.end())	continue;
			if (board[cur.first][cur.second] == '.')	continue;
			temp.insert(cur);
			//cout << "\t" << cur.first << ", " << cur.second << " bomb \n";
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > r || next_j > c)
					continue;
				temp.insert({ next_i,next_j });
			}
		}
		broken.clear();
		for (iter = temp.begin(); iter != temp.end(); iter++) {
			if (board[iter->first][iter->second] == 'O')
				broken.insert(*iter);
			board[iter->first][iter->second] = '.';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> n;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'O')
				q1.push({ i, j });
		}
	}
	int t = 1;
	
	while (t < n) {
		t++;
		setBomb();
		if (t == n)	break;

		t++;
		Timeout();
	}
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
			cout << board[i][j];
		cout << "\n";
	}
	return 0;
}