#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[501];
vector<int> v[501];
int dp[501];
bool complete[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cin >> x;
		while (x != -1) {
			v[i].push_back(x);
			cin >> x;
		}
		if (v[i].size() == 0) {
			complete[i] = true;
			dp[i] = arr[i];
		}
	}
	int cnt = 0;
	bool flag = true;
	while (1) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (complete[i])	continue;
			flag = true;
			for (int j = 0; j < v[i].size(); j++) 
				flag &= complete[v[i][j]];
			if (flag) {
				for (int j = 0; j < v[i].size(); j++) {
					dp[i] = max(dp[i], dp[v[i][j]]);
				}
				dp[i] += arr[i];
				complete[i] = true;
			}
			cnt++;
		}
		if (cnt == 0)
			break;
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i] << "\n";
	
	return 0;
}