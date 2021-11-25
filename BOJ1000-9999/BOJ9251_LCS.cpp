#include <iostream>
#include <algorithm>
using namespace std;

int memo[4001][4001] = { 0, };

int main() {
	string a, b;
	cin >> a >> b;
	a = "0" + a;
	b = "0" + b;
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j])	memo[i][j] = memo[i - 1][j - 1] + 1;
			else	memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
		}
	}
	cout << memo[a.size() - 1][b.size() - 1];
	return 0;
}