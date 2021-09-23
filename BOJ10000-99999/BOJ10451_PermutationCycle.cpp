#include <iostream>
using namespace std;

int link[1001] = { 0, };
bool visited[1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)	visited[i] = false;
		for (int i = 1; i <= n; i++) {
			cin >> link[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				cnt++;
				visited[i] = true;
				int next = link[i];
				while (next != i) {
					visited[next] = true;
					next = link[next];
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}