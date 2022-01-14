#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;
stack<pair<int, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int height;
	for (int i = 1; i <= n; i++) {
		cin >> height;
		while (!stk.empty() && stk.top().first < height) {
			stk.pop();
		}
		if (stk.empty())	cout << 0 << " ";
		else	cout << stk.top().second << " ";
		stk.push({ height, i });
	}
	return 0;
}