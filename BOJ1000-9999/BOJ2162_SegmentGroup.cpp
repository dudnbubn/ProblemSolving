#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<pair<int, int>, pair<int, int>> coordinates[3001];
vector<int> adj_list[3001];
bool visited[3001];

int get_ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	long long result = ((long long)x1 * y2 + x2 * y3 + x3 * y1) - ((long long)x2 * y1 + x3 * y2 + x1 * y3);
	if (result > 0)	return 1;
	else if (result == 0)	return 0;
	else	return -1;
}

bool in_range(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (x1 < x2) {
		if ((x3 < x1 && x4 < x1) || (x3 > x2 && x4 > x2))	return false;
	}
	else {
		if ((x3 < x2 && x4 < x2) || (x3 > x1 && x4 > x1))	return false;
	}
	if (y1 < y2) {
		if ((y3 < y1 && y4 < y1) || (y3 > y2 && y4 > y2))	return false;
	}
	else {
		if ((y3 < y2 && y4 < y2) || (y3 > y1 && y4 > y1))	return false;
	}
	return true;
}

bool is_linked(int l1, int l2) {
	int x1 = coordinates[l1].first.first, y1 = coordinates[l1].first.second;
	int x2 = coordinates[l1].second.first, y2 = coordinates[l1].second.second;
	int x3 = coordinates[l2].first.first, y3 = coordinates[l2].first.second;
	int x4 = coordinates[l2].second.first, y4 = coordinates[l2].second.second;

	int ccw1 = get_ccw(x1, y1, x2, y2, x3, y3) * get_ccw(x1, y1, x2, y2, x4, y4);
	int ccw2 = get_ccw(x3, y3, x4, y4, x1, y1) * get_ccw(x3, y3, x4, y4, x2, y2);
	
	if (ccw1 == 0 && ccw2 == 0) 
		return in_range(x1, y1, x2, y2, x3, y3, x4, y4);
	return (ccw1 <= 0 && ccw2 <= 0);
}

int DFS(int node) {
	visited[node] = true;

	int result = 1;
	for (int adj : adj_list[node]) {
		if (visited[adj])	continue;
		result += DFS(adj);
		
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> coordinates[i].first.first >> coordinates[i].first.second >> coordinates[i].second.first >> coordinates[i].second.second;

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (is_linked(i, j)) {
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
			}
		}
	}

	int result = 0, maximum = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i])	continue;
		result++;
		int dfs = DFS(i);
		maximum = maximum > dfs ? maximum : dfs;
	}
	cout << result << "\n" << maximum;
	return 0;
}