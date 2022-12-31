#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> coordinates[1000];
int dist[1000][1000];


void get_distance(int p1, int p2) {
	int x1 = coordinates[p1].first, y1 = coordinates[p1].second;
	int x2 = coordinates[p2].first, y2 = coordinates[p2].second;
	
	dist[p1][p2] = dist[p2][p1] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)	
		cin >> coordinates[i].first >> coordinates[i].second;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			get_distance(i, j);
		}
	}

	int result = 0;
	int maximum = 1e9;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)	continue;
			temp = temp > dist[i][j] ? temp : dist[i][j];
		}
		if (maximum > temp) {
			maximum = temp;
			result = i;
		}
	}
	cout << coordinates[result].first << " " << coordinates[result].second;
}