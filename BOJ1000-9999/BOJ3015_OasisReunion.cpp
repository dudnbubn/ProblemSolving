#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<pair<int, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int input;
	cin >> input;
	stk.push({ input, 1 });

	long long result = 0;
	int cnt, equal_cnt;
	bool equal;
	for (int i = 1; i < N; i++) {
		cin >> input;
		cnt = 0;
		equal = false;
		while (!stk.empty() && stk.top().first <= input) {
			if (stk.top().first == input) {
				equal = true;
				equal_cnt = stk.top().second + 1;
			}
			cnt += stk.top().second;
			stk.pop();
		}
		if (!stk.empty())	cnt++;
		result += cnt;
		
		if (equal)	stk.push({ input, equal_cnt });
		else	stk.push({ input, 1 });
	}
	cout << result;

	return 0;
}