#include <iostream>
#include <queue>

using namespace std;

#define MAXIMUM 2001

queue<pair<int, int>> q;
bool visited[MAXIMUM][MAXIMUM];

int main() {
	int S;
	cin >> S;

	q.push({ 1, 0 });
	visited[1][0] = true;
	pair<int, int> cur;
	int t = -1, qsz;
	while (!q.empty()) {
		t++;
		qsz = q.size();
		for (int sz = 0; sz < qsz; sz++) {
			cur = q.front();
			q.pop();

			if (cur.first == S) {
				cout << t;
				return 0;
			}

			if (!visited[cur.first][cur.first]) {
				visited[cur.first][cur.first] = true;
				q.push({ cur.first, cur.first });
			}
			if ((cur.first + cur.second < MAXIMUM) && !visited[cur.first + cur.second][cur.second]) {
				visited[cur.first + cur.second][cur.second] = true;
				q.push({ cur.first + cur.second , cur.second });
			}
			if (cur.first > 0 && !visited[cur.first - 1][cur.second]) {
				visited[cur.first - 1][cur.second] = true;
				q.push({ cur.first - 1,cur.second });
			}
		}
	}
	return 0;
}