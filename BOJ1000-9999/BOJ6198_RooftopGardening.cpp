#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int arr[80000];
stack<pair<int, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	
	stk.push({ 1000000000, n });
	long long result = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (1) {
			if (stk.top().first >= arr[i]) {
				result += (stk.top().second - i - 1);
				break;
			}
			stk.pop();
		}
		stk.push({ arr[i], i });
	}
	
	cout << result;
	return 0;
}