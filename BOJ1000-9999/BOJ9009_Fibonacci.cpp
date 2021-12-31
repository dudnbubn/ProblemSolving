#include <iostream>
#include <stack>
using namespace std;

long long fibo[45];
stack<int> result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i < 45; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 44; i >= 1; i--) {
			if (n >= fibo[i]) {
				result.push(fibo[i]);
				n -= fibo[i];
				if (n == 0)	break;
			}
		}
		while (!result.empty()) {
			cout << result.top() << " ";
			result.pop();
		}
		cout << "\n";
	}
	return 0;
}