#include <iostream>
using namespace std;

int snail[1000][1000] = { 0, };
int di[4] = { 1,0,-1,0 };
int dj[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, target, result_i = 0, result_j = 0;
	cin >> n >> target;
	int len = n, cnt = 1;
	int temp = n * n;
	int i = 1, j = 1, dir = 0;
	while (temp > 0) {
		cnt++;
		for (int l = 0; l < len; l++, i += di[dir], j += dj[dir]) {
			snail[i][j] = temp;
			if (temp == target) {
				result_i = i;
				result_j = j;
			}
			temp--;
		}
		i -= di[dir];
		j -= dj[dir];
		dir = (dir + 1) % 4;
		i += di[dir];
		j += dj[dir];

		if (cnt == 2) {
			cnt = 0;
			len--;
		}
	}
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) 
			cout << snail[i][j] << " ";
		cout << "\n";
	}
	cout << result_i << " " << result_j;
	return 0;
}