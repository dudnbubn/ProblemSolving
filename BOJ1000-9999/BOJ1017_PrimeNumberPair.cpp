#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[51];
int linked_by[51];
bool is_prime[2000];
bool is_visited[51];

vector<int> adjacent_list[51];

void eratos() {
	for (int i = 2; i < 2000; i++)	is_prime[i] = true;
	for (int i = 2; i < 2000; i++) {
		if (!is_prime[i])	continue;
		for (int j = i * i; j < 2000; j += i)
			is_prime[j] = false;
	}
}

bool DFS(int node, int except) {
	if (is_visited[node])	return false;
	is_visited[node] = true;

	for (int adjacent : adjacent_list[node]) {
		if (adjacent == except || adjacent == 1)	continue;
		if (!linked_by[adjacent] || DFS(linked_by[adjacent], except)) {
			linked_by[adjacent] = node;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	eratos();
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (!is_prime[arr[i] + arr[j]])	continue;
			adjacent_list[i].push_back(j);
			adjacent_list[j].push_back(i);
		}
	}

	vector<int> results;
	for (int adjacent : adjacent_list[1]) {
		int cnt = 0;
		for (int i = 1; i <= N; i++)	linked_by[i] = 0;
		for (int i = 2; i <= N; i++) {
			if (i == adjacent)	continue;

			for (int j = 1; j <= N; j++)	is_visited[j] = false;
			is_visited[1] = is_visited[adjacent] = true;
			if (DFS(i, adjacent))	cnt++;
		}

		if (cnt == N - 2)	results.push_back(arr[adjacent]);
	}

	if (results.empty())	cout << -1;
	else {
		sort(results.begin(), results.end());
		for (int result : results)
			cout << result << " ";
	}
	return 0;
}