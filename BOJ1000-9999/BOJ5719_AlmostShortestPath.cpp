#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> Info;

int N, M;
vector<pair<int, int>> adj_list[500];
int weights[500];
bool visited[500];
priority_queue<Info, vector<Info>, greater<Info>> pq;
vector<int> prevs[500];
bool except[500][500];

void clear_visited() {
	memset(visited, 0, sizeof(visited));
}

void init() {
	memset(except, 0, sizeof(except));
	clear_visited();
	pq = {};
	for (int i = 0; i < N; i++) { 
		prevs[i] = {};
		adj_list[i] = {};
	}
}

int Dijkstra(int start, int end) {
	int result = -1;
	pq.push({ { 0, start }, -1 });
	
	Info current;
	int weight, number, prev;
	while (!pq.empty()) {

		current = pq.top();
		pq.pop();

		weight = current.first.first;
		number = current.first.second;
		prev = current.second;

		if (weights[number] == weight)
			prevs[number].push_back(prev);

		if (visited[number])	continue;

		weights[number] = weight;
		prevs[number].push_back(prev);
		visited[number] = true;
		if (number == end)	result = weight;

		for (pair<int, int> adj : adj_list[number]) {
			int next = adj.second;
			if (visited[next] || except[number][next])	continue;
			pq.push({ {weight + adj.first, next}, number });
		}
	}
	return result;
}

void except_edges(int number) {
	if (visited[number])	return;
	visited[number] = true;

	for (int prev : prevs[number]) {
		if (prev == -1)	continue;
		except[prev][number] = true;
		except_edges(prev);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	int start, end;

	int U, V, P;
	while (N || M) {
		init();
		cin >> start >> end;
		
		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			adj_list[U].push_back({ P, V });
		}
		Dijkstra(start, end);

		clear_visited();
		except_edges(end);

		clear_visited();
		cout << Dijkstra(start, end) << "\n";

		cin >> N >> M;
	}
	return 0;
}