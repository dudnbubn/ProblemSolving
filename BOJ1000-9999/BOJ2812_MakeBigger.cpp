#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int n, k;
stack<char> result_stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	string input;
	cin >> input;
	
	string result = "";
	int index;
	for (index = 0; index < input.size(); index++) {
		result_stk.push(input[index]);
		if (index == input.size() - 1)	break;
		
		while (!result_stk.empty() && result_stk.top() < input[index + 1]) {
			result_stk.pop();
			k--;
			if (k == 0)	break;
		}
		if (k == 0)	break;
	}

	while (k) {
		result_stk.pop();
		k--;
	}

	while (!result_stk.empty()) {
		result = result_stk.top() + result;
		result_stk.pop();
	}
	result = result + input.substr(index + 1);
	
	cout << result;
	
	return 0;
}