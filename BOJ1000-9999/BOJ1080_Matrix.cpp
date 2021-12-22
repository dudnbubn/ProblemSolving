#include <iostream>
using namespace std;

char A[51][51];
char B[51][51];

void reverse(int i, int j) {
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			if (A[a + i][b + j] == '1')	A[a + i][b + j] = '0';
			else	A[a + i][b + j] = '1';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> B[i][j];
	
	int cnt = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 2; j++) {
			if (A[i][j] != B[i][j]) {
				reverse(i, j);
				cnt++;
			}
		}
	}
	
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i][j] != B[i][j]) {
				flag = false;
				break;
			}
		}
		if (!flag)	break;
	}
	if (flag)	cout << cnt;
	else	cout << -1;
	return 0;
}