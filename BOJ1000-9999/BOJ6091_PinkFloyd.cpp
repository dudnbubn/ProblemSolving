#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> Node;

vector<Node> node_list;

int N;
int root[1025];
vector<int> results[1025];

int Find(int x) {
	if (root[x] == x)	return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	root[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)	root[i] = i;

	int input;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			cin >> input;
			node_list.push_back({ input, {i, j} });
		}
	}
	
	sort(node_list.begin(), node_list.end());

	int from, to;
	for (Node node : node_list) {
		from = node.second.first;
		to = node.second.second;

		if (Find(from) == Find(to))	continue;
		Union(from, to);

		results[from].push_back(to);
		results[to].push_back(from);

	}
	
	for (int i = 1; i <= N; i++) {
		sort(results[i].begin(), results[i].end());

		cout << results[i].size() << " ";
		for (int result : results[i])
			cout << result << " ";
		cout << "\n";
	}
	return 0;
}