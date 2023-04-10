#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100'000
#define INF 1'000'000'000

int N;
int energies[MAX_N + 1];
bool is_visited[MAX_N + 1];
pair<int, long long> parents[20][MAX_N + 1];


vector<pair<int, int>> children[MAX_N + 1];

void DFS(int current) {
	is_visited[current] = true;

	int number, dist;
	for (pair<int, int> child : children[current]) {
		number = child.first;
		dist = child.second;
		if (is_visited[number])	continue;
		parents[0][number] = { current, dist };
		DFS(number);
	}
}

void set_parents() {
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= N; j++) {
			parents[i][j].first = parents[i - 1][parents[i - 1][j].first].first;
			parents[i][j].second = parents[i - 1][parents[i - 1][j].first].second + parents[i - 1][j].second;
		}
	}
}

int get_destination(int number) {
	int energy = energies[number];
	for (int i = 19; i >= 0; i--) {
		if (energy >= parents[i][number].second) {
			energy -= parents[i][number].second;
			number = parents[i][number].first;
		}
	}
	return number;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < MAX_N + 1; j++)
			parents[i][j].second = INF;

	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> energies[i];

	int a, b, c;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		children[a].push_back({ b, c });
		children[b].push_back({ a, c });
	}
	
	DFS(1);
	set_parents();

	for (int i = 1; i <= N; i++) {
		cout << get_destination(i) << "\n";
	}
}