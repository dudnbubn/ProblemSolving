#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

priority_queue<int, vector<int>> pos;
priority_queue<int, vector<int>, greater<int>> neg;

int main() {
	int n, m;
	cin >> n >> m;
	int x;
	int move = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > 0)	pos.push(x);
		else	neg.push(x);
	}
	if (pos.empty()) {
		move = abs(neg.top());
		for (int i = 0; i < m; i++) {
			if (neg.empty())
				break;
			neg.pop();
		}
		while (!neg.empty()) {
			move += (2 * abs(neg.top()));
			for (int i = 0; i < m; i++) {
				if (neg.empty())
					break;
				neg.pop();
			}
		}
	}
	else if (neg.empty()) {
		move = pos.top();
		for (int i = 0; i < m; i++) {
			if (pos.empty())
				break;
			pos.pop();
		}
		while (!pos.empty()) {
			move += (2 * pos.top());
			for (int i = 0; i < m; i++) {
				if (pos.empty())
					break;
				pos.pop();
			}
		}
	}
	else {
		if (pos.top() >= abs(neg.top())) {
			move = pos.top();
			for (int i = 0; i < m; i++) {
				if (pos.empty())
					break;
				pos.pop();
			}
		}
		else {
			move = abs(neg.top());
			for (int i = 0; i < m; i++) {
				if (neg.empty())
					break;
				neg.pop();
			}
		}
		while (!pos.empty()) {
			move += (2 * pos.top());
			for (int i = 0; i < m; i++) {
				if (pos.empty())
					break;
				pos.pop();
			}
		}
		while (!neg.empty()) {
			move += (2 * abs(neg.top()));
			for (int i = 0; i < m; i++) {
				if (neg.empty())
					break;
				neg.pop();
			}
		}
	}
	cout << move;
	return 0;
}