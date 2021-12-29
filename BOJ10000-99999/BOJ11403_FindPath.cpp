// key point : floyd-warshall algorithm

#include <iostream>
using namespace std;

int n;
bool adj[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j];
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (adj[i][k]) {
				for (int j = 1; j <= n; j++) {
					adj[i][j] |= adj[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}