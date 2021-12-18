// knapsack

#include <iostream>
#include <algorithm>
using namespace std;

int weight[101];
int value[101];
int item[101][10001] = { 0, };

int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (weight[i] <= j)
				item[i][j] = max(item[i - 1][j], item[i - 1][j - weight[i]] + value[i]);
			else
				item[i][j] = item[i - 1][j];
		}
	}
	cout << item[n][t];
	return 0;
}