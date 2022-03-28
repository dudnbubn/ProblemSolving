#include <iostream>
#include <queue>

using namespace std;

bool visited[10000];

int D(int A) {
	return (A * 2) % 10000;
}

int S(int A) {
	return (A + 9999) % 10000;
}

int L(int A) {
	return (A / 1000) + (A % 1000) * 10;
}

int R(int A) {
	return (A % 10) * 1000 + A / 10;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	int A, B, d, s, l, r;
	queue<pair<int, string>> q;
	while (t--) {
		cin >> A >> B;
		q = {};
		q.push({ A, "" });
		for (int i = 0; i < 10000; i++)	visited[i] = false;
		pair<int, string> cur;
		int result = 0;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (cur.first == B) {
				cout << cur.second << "\n";
				break;
			}
			if (!visited[d = D(cur.first)]) {
				visited[d] = true;
				q.push({ d, cur.second + 'D' });
			}
			if (!visited[s = S(cur.first)]) {
				visited[s] = true;
				q.push({ s, cur.second + 'S' });
			}
			if (!visited[l = L(cur.first)]) {
				visited[l] = true;
				q.push({ l, cur.second + 'L' });
			}
			if (!visited[r = R(cur.first)]) {
				visited[r] = true;
				q.push({ r, cur.second + 'R' });
			}
		}
	}
	return 0;
}