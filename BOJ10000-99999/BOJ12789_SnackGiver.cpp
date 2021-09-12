#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> vertical;
queue<int> horizon;
int n, num;

int main() {
	cin >> n;
	int next = 1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		horizon.push(num);
	}
	while(!horizon.empty()) {
		if (!horizon.empty() && horizon.front() == next) {
			next++;
			horizon.pop();
		}
		else if (!vertical.empty() && vertical.top() == next) {
			vertical.pop();
			next++;
		}
		else {
			if ((!horizon.empty() && !vertical.empty()) && (horizon.front() > vertical.top())) {
				cout << "Sad";
				return 0;
			}
			vertical.push(horizon.front());
			horizon.pop();
		}
	}

	int vsz = vertical.size();
	for (int i = 0; i < vsz; i++) {
		if (vertical.top() == next) {
			vertical.pop();
			next++;
		}
		else	
			break;
	}
	if (vertical.empty())	cout << "Nice";
	else	cout << "Sad";

	return 0;
}