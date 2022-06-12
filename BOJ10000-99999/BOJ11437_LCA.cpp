#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int depth[50001];
bool visited[50001];
int p[50001][20];
vector<int> adj_list[50001];

void DFS(int num, int d) {
	visited[num] = true;
	depth[num] = d;
	for (int adj : adj_list[num]) {
		if (!visited[adj]) {
			p[adj][0] = num;
			DFS(adj, d + 1);
		}
	}
}

void getAncestor() {
	for (int j = 1; j < 20; j++) 
		for (int i = 1; i <= N; i++) 
			p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	
	for (int i = 19; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i))
			b = p[b][i];
	}
	if (a == b)	return a;

	for (int i = 19; i >= 0; i--) {
		if (p[a][i] != p[b][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	DFS(1, 0);
	getAncestor();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	return 0;
}