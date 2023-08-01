#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main() {
	int N, K, M;
	cin >> N >> K >> M;
	for (int n = 1; n <= N; n++)	dq.push_back(n);

	bool right_order = true;
	int m = 0;
	while (N--) {
		if (right_order) {
			for (int k = 0; k < K - 1; k++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front() << "\n";
			dq.pop_front();
		}
		else {
			for (int k = 0; k < K - 1; k++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back() << "\n";
			dq.pop_back();
		}
		m++;
		if (m == M) {
			m = 0;
			right_order = !right_order;
		}
	}
}