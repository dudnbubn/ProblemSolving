#include <iostream>
#include <map>
#include <queue>

using namespace std;

queue<string> q;
map<string, bool> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		m.insert({ input, false });
		q.push(input);
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		while (m[q.front()]) {
			q.pop();
		}
		if (q.front() != input) {
			result++;
			m[input] = true;
		}
		else
			q.pop();
	}
	cout << result;
	return 0;
}