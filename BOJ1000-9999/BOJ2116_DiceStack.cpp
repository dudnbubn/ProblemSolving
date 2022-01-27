#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dice[10001][7];

int Recur(int k, int num) {	
	int index;
	for (index = 1; index <= 6; index++)
		if (dice[k][index] == num)
			break;
	
	int other;
	int maximum;
	if (index == 1 || index == 6) {
		if (index == 1)	other = 6;
		else	other = 1;
		maximum = max(max(dice[k][2], dice[k][3]), max(dice[k][4], dice[k][5]));
	}
	else if (index == 2 || index == 4) {
		if (index == 2)	other = 4;
		else	other = 2;
		maximum = max(max(dice[k][1], dice[k][3]), max(dice[k][6], dice[k][5]));
	}
	else {
		if (index == 3)	other = 5;
		else	other = 3;
		maximum = max(max(dice[k][2], dice[k][1]), max(dice[k][4], dice[k][6]));
	}

	if (k == n + 1)	return maximum;
	else	return maximum + Recur(k + 1, dice[k][other]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> dice[i][j];
		}
	}
	int maximum = 0;
	for (int i = 1; i <= 6; i++)
		maximum = max(maximum, Recur(1, i));
	cout << maximum;
	return 0;
}