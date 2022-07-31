#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

stack<int> stk;
vector<pair<int, int>> position;
set<string> result;
bool visited[10];

void recur(string r, int k) {
	string temp = "";

	if (k == position.size()) {
		for (int i = 0; i < r.size(); i++) {
			if (r[i] == ' ')	continue;
			temp = temp + r[i];
		}
		result.insert(temp);
		return;
	}
	
	for (int i = 0; i < r.size(); i++) {
		if (i == position[k].first || i == position[k].second)
			temp = temp + ' ';
		else
			temp = temp + r[i];
	}
	recur(r, k + 1);
	recur(temp, k + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else if (s[i] == ')') {
			position.push_back({ stk.top(), i });
			stk.pop();
		}
	}

	recur(s, 0);

	for (string r : result) {
		if (r == s)	continue;
		cout << r << "\n";
	}
		

	return 0;
}