#include <iostream>
#include <stack>

using namespace std;

stack<int> factors;

int euler(int N) {
	int temp = N, factor = 2;
	while (factor <= temp) {
		if (temp % factor == 0) {
			if (factors.empty() || factors.top() != factor)	factors.push(factor);
			temp /= factor;
		}
		else
			factor++;
	}
	
	while (!factors.empty()) {
		factor = factors.top();
		factors.pop();

		N = (N / factor) * (factor - 1);
	}
	return N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	while (N > 0) {
		cout << euler(N) << "\n";
		cin >> N;
	}

	return 0;
}