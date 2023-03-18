#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 50
typedef pair<int, pair<int, int>> Shark;

int N;
Shark sharks[MAX_N];
vector<int> feeds[MAX_N];
bool is_visited[2 * MAX_N];
int predator_of[MAX_N];

bool is_bigger(Shark a, Shark b) {
	return (a.first >= b.first && a.second.first >= b.second.first && a.second.second >= b.second.second);
}

bool DFS(int current) {
	cout << "DFS(" << current << ")\n";
	if (is_visited[current])	return false;
	is_visited[current] = true;

	for (int feed : feeds[current / 2]) {
		if (predator_of[feed] == -1 || DFS(predator_of[feed])) {
			predator_of[feed] = current;
			cout << "predator_of[" << feed << "] = " << current << "\n";
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int size, speed, intelligence;
	for (int i = 0; i < N; i++) {
		cin >> size >> speed >> intelligence;
		sharks[i] = { size, {speed, intelligence} };
		for (int j = 0; j < i; j++) {
			if (is_bigger(sharks[i], sharks[j]))
				feeds[i].push_back(j);
			else if (is_bigger(sharks[j], sharks[i]))
				feeds[j].push_back(i);
		}
		predator_of[i] = -1;
	}

	int result = 0;
	for (int i = 0; i < N * 2; i++) {
		cout << "i = " << i << "\n";
		for (int j = 0; j < N * 2; j++)	is_visited[j] = false;
		if (DFS(i)) {
			result++;
			cout << "result++\n";
		}
	}
	cout << N - result;
	return 0;
}