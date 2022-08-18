#include <iostream>
#include <vector>

using namespace std;

int N, M;
int p[100001][20];
int level[100001];
bool visited[100001];

vector<int> adj_list[100001];

void link(int a, int b) {
	adj_list[a].push_back(b);
	adj_list[b].push_back(a);
}
	

void DFS(int n, int lv) {
	visited[n] = true;
	level[n] = lv;
	for (int adj : adj_list[n]) {
		if (visited[adj])	continue;
		p[adj][0] = n;
		DFS(adj, lv + 1);
	}
};

void getAncestor() {
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= N; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b) {
	if (level[a] < level[b])	swap(a, b);
	
	for (int i = 19; i >= 0; i--) {
		if (level[a] - level[b] >= (1 << i))
			a = p[a][i];
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
		link(a, b);
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