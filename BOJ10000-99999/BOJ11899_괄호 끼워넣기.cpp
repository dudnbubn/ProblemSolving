#include <iostream>
#include <stack>

using namespace std;

stack<char> stk;

int main() {
	string s;
	cin >> s;
	for (char c : s) {
		if (stk.empty() || c == '(')	stk.push(c);
		else {
			if (stk.top() == '(') stk.pop();
			else	stk.push(c);
		}
	}
	cout << stk.size();
}