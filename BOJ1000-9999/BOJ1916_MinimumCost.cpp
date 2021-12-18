#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;
int weight[1001][1001];
int status[1001] = { 0, };
int dist[1001];

void Dijkstra(int start) {
	//cout << start << "���� ����..\n";
	status[start] = 2;
	dist[start] = 0;
	for (int i = 1; i <= n; i++) {
		if (weight[start][i] > -1 && status[i] < 2) {
			status[i] = 1;
			//cout << "\t������ ��� " << i << "���� ���µ� ��� ��� min(" << dist[i] << ", " << dist[start] + weight[start][i] << ") �� ������Ʈ\n";
			dist[i] = min(dist[i], dist[start] + weight[start][i]);
			
		}
	}
	int minimum, min_index = 0;
	for (int i = 0; i < n - 1; i++) {
		minimum = INF;
		for (int j = 1; j <= n; j++) {
			if (status[j] == 1) {
				if (minimum > dist[j]) {
					minimum = dist[j];
					min_index = j;
				}
			}
		}
		//cout << "���� ��� ��� : " << min_index << ", ��� : " << dist[i] << "\n";
		
		status[min_index] = 2;
		for (int j = 1; j <= n; j++) {
			if (weight[min_index][j] > -1 && status[j] < 2) {
				status[j] = 1;
				//cout << "\t������ ��� " << j << "���� ���µ� ��� ��� min(" << dist[j] << ", " << dist[min_index] + weight[min_index][j] << ") �� ������Ʈ\n";
				dist[j] = min(dist[j], dist[min_index] + weight[min_index][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 1000; i++){
		dist[i] = INF;
		for (int j = 1; j <= 1000; j++) {
			weight[i][j] = -1;
		}
	}

	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		if (weight[u][v] == -1)	weight[u][v] = w;
		else	weight[u][v] = min(weight[u][v], w);
	}
	
	cin >> u >> v;
	Dijkstra(u);
	cout << dist[v];

	return 0;
}