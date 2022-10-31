#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string str, explosion;
stack<pair<char, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str >> explosion;
	int str_size = str.size();
	int exp_size = explosion.size();

	for (char c : str) {
		if (c == explosion[0])
			stk.push({ c, 0 });
		else {
			if (stk.empty())
				stk.push({ c, -1 });
			else {
				if (c == explosion[stk.top().second + 1])
					stk.push({ c, stk.top().second + 1 });
				else
					stk.push({ c, -1 });
			}
		}

		if (stk.top().second == exp_size - 1) {
			for (int i = 0; i < exp_size; i++)
				stk.pop();
		}
	}

	if (stk.empty())
		cout << "FRULA";
	else {
		stack<char> result;
		while (!stk.empty()) {
			result.push(stk.top().first);
			stk.pop();
		}
		while (!result.empty()) {
			cout << result.top();
			result.pop();
		}
	}
	return 0;
}