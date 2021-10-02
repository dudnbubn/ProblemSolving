#include <iostream>
#include <algorithm>
using namespace std;

int n;
int bed[11][11];
int minimum = 1000000000;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int visited[11][11] = { 0, };

void Brute(int cur_i, int cur_j, int cnt, int sum) {
	if (cnt == 3) {
		minimum = min(minimum, sum);
		return;
	}
	for (int i = cur_i; i < n; i++) {
		for (int j = cur_j; j < n; j++) {
			if(!visited[i][j]){
				bool flag = true;
				for (int k = 0; k < 4; k++) {
					if (visited[i + di[k]][j + dj[k]]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					int temp = bed[i][j];
					visited[i][j] = true;
					for (int k = 0; k < 4; k++) {
						visited[i + di[k]][j + dj[k]] = true;
						temp += bed[i + di[k]][j + dj[k]];
					}
					if (j <= n - 4)	Brute(i, j + 3, cnt + 1, sum + temp);
					else	Brute(i + 1, 2, cnt + 1, sum + temp);
					visited[i][j] = false;
					for (int k = 0; k < 4; k++) 
						visited[i + di[k]][j + dj[k]] = false;
				}
			}
		}
		cur_j = 2;
	}

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> bed[i][j];
	Brute(2, 2, 0, 0);
	cout << minimum;
	return 0;
}