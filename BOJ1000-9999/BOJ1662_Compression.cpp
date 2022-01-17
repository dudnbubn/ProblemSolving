// key point : stack

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<pair<int, int>> stk;

int main() {
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ')') {
			pair<int, int> cur = stk.top();
			if(stk.top().first == -1){
				stk.pop();
				stk.pop();
				continue;
			}
			stk.pop();
			while (!stk.empty() && stk.top().first != -1) {
				cur.second += stk.top().second;
				stk.pop();
			}
			if (!stk.empty()) {
				stk.pop();
				cur.second *= stk.top().first;
				stk.pop();
			}
			stk.push(cur);
			
		}
		else {
			if (input[i] == '(')
				stk.push({ -1, 1 });
			else
				stk.push({ input[i] - '0', 1 });
		}
	}
	int result = 0;
	while (!stk.empty()) {
		result += stk.top().second;
		stk.pop();
	}
	cout << result;
	return 0;
}