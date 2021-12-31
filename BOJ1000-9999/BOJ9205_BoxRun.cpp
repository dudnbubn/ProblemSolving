#include <iostream>
#include <algorithm>
using namespace std;

int n;
int start_x, start_y, end_x, end_y;
pair<int, int> conv[101];
bool visited[101] = { 0, };

bool DFS(int cur_x, int cur_y) {
	int dx = end_x - cur_x;
	int dy = end_y - cur_y;
	if (dx < 0)	dx *= -1;
	if (dy < 0)	dy *= -1;
	if (dx + dy <= 1000)
		return true;

	for (int i = 0; i < n; i++) {
		dx = conv[i].first - cur_x;
		dy = conv[i].second - cur_y;
		if (dx < 0)	dx *= -1;
		if (dy < 0)	dy *= -1;
		if ((dx + dy <= 1000) && !visited[i]) {
			visited[i] = true;
			if (DFS(conv[i].first, conv[i].second))	return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 101; i++)	visited[i] = false;

		cin >> n;
		cin >> start_x >> start_y;
		for (int i = 0; i < n; i++)	cin >> conv[i].first >> conv[i].second;
		cin >> end_x >> end_y;
		if (DFS(start_x, start_y))	cout << "happy\n";
		else	cout << "sad\n";
	}
	return 0;
}