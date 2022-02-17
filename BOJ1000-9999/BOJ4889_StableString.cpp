#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<char> stk;
	string input;
	int t = 1;
	cin >> input;
	while (input[0] != '-') {
		stk = {};
		int result = 0;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '{')	stk.push('{');
			else {
				if (stk.empty()) {
					result++;
					stk.push('{');
				}
				else {
					if (stk.top() == '{')	stk.pop();
				}
			}
		}
		cout << t++ << ". " << result + stk.size() / 2 << "\n";
		cin >> input;
	}
	return 0;
}