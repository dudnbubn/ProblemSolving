#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int N;
	cin >> N;

	int x;
	while (true) {
		cin >> x;
		if (x == -1)	break;
		
		if (x == 0 && !q.empty()) {
			if (!q.empty())	q.pop();
		}
		else {
			if (q.size() < N)	q.push(x);
		}
	}

	if (q.empty())	cout << "empty";
	else {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}
	
}