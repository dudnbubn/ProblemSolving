#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, cnt = 0;
	string s;
	stack<char> stk;
	cin >> n;
	for (int i = 0; i < n; i++) {
		while (!stk.empty())	stk.pop();
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (stk.empty())	stk.push(s[j]);
			else {
				if (stk.top() == s[j])	stk.pop();
				else	stk.push(s[j]);
			}
		}
		if (stk.empty())	cnt++;
	}
	cout << cnt;
	return 0;
}