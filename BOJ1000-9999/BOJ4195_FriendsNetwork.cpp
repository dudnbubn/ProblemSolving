#include <iostream>
#include <unordered_map>

using namespace std;

int hash_value;
unordered_map<string, int> um;

int parent[200001];
int relation_size[200001];

int Find(int x) {
	if (x == parent[x])	return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	parent[y] = x;
	relation_size[x] += relation_size[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	int F;
	string a, b;
	while (T--) {
		cin >> F;

		hash_value = 0;
		um = {};
		for (int i = 0; i <= 2 * F; i++) {
			parent[i] = i;
			relation_size[i] = 0;
		}
		for (int f = 0; f < F; f++) {
			cin >> a >> b;

			if (um.find(a) == um.end()) {
				um[a] = hash_value++;
				relation_size[um[a]] = 1;
			}
			if (um.find(b) == um.end()) {
				um[b] = hash_value++;
				relation_size[um[b]] = 1;
			}

			if (Find(um[a]) != Find(um[b]))
				Union(um[a], um[b]);

			cout << relation_size[Find(um[a])] << "\n";
		}
	}
	return 0;
}