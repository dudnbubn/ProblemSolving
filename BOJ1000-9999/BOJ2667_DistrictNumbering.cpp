// 모든 점에 대해 돌면서 해당 점이 집이 있고 이전에 방문하지 않은 곳이면 DFS를 돈다.
// DFS를 돌면서 연결된 모든 집의 개수를 카운트하고 방문했다고 표시하면 해결된다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
bool district[26][26] = { 0, };
bool visited[26][26] = { 0, };
int di[4] = { 0, -1, 0 , 1 };
int dj[4] = { -1, 0, 1, 0 };
vector<int> answer;

void DFS(int i, int j) {
	cnt++;
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int temp_i = i + di[k];
		int temp_j = j + dj[k];
		if (temp_i < 1 || temp_i >n || temp_j <1 || temp_j >n)
			continue;
		if (district[temp_i][temp_j] && !visited[temp_i][temp_j]) {
			DFS(temp_i, temp_j);
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char temp;
			cin >> temp;
			if (temp == '1') district[i][j] = true;
			else	district[i][j] = false;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (district[i][j] && !visited[i][j]) {
				cnt = 0;
				DFS(i, j);
				answer.push_back(cnt);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i : answer)
		cout << i << "\n";
	return 0;
}