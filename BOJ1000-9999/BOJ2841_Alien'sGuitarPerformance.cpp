#include <iostream>
#include <stack>

using namespace std;

stack<int> stk[7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	cin >> n >> p;
	int line, fret;
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> line >> fret;
		if (stk[line].empty() || stk[line].top() < fret) {
			stk[line].push(fret);
			result++;
		}
		else if (stk[line].top() == fret)
			continue;
		else {
			while (!stk[line].empty() && stk[line].top() > fret) {
				result++;
				stk[line].pop();
			}
			if (stk[line].empty() || stk[line].top() < fret) {
				result++;
				stk[line].push(fret);
			}
		}
	}
	cout << result;
	return 0;
}