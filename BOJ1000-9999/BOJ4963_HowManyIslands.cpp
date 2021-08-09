// 전형적인 DFS를 이용해 푸는 문제이다.
// 다만 대각선으로도 이동할 수 있다는 점과 테스트케이스마다 visited를 초기화해줘야 한다는 점을 인지하도록 하자.
#include <iostream>
using namespace std;

int w, h;
bool map[55][55] = { 0, };
bool visited[55][55] = { 0, };
int cnt = 0;
int di[8] = { -1, -1, -1, 0, 1,1,1,0 };
int dj[8] = { -1,0,1,1,1,0,-1,-1 };

void DFS(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 8; k++) {
		int temp_i = i + di[k];
		int temp_j = j + dj[k];
		if (temp_i < 1 || temp_i > h || temp_j < 1 || temp_j >w)
			continue;
		if (map[temp_i][temp_j] && !visited[temp_i][temp_j]) {
			DFS(temp_i, temp_j);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h;
	while (w != 0 && h != 0) {
		cnt = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int x;
				cin >> x;
				if (x == 1)	map[i][j] = true;
				else	map[i][j] = false;
				visited[i][j] = 0;
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] && !visited[i][j]) {
					cnt++;
					DFS(i, j);
				}
			}
		}
		cout << cnt << "\n";
		cin >> w >> h;
	}
	return 0;
}