#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;
int A[11][11];
int nutrient[11][11];
int S2D2[11][11];
int breed[11][11];
vector<int> trees[11][11];
vector<int> die[11][11];
vector<int> new_tree;
int di[8] = { -1, -1, -1, 0, 1, 1, 1, 0, };
int dj[8] = { -1, 0, 1, 1, 1, 0 , -1, -1 };

void spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			new_tree = {};
			sort(trees[i][j].begin(), trees[i][j].end());

			for (int k= 0, sz = trees[i][j].size(); k < sz; k++) {
				if (nutrient[i][j] >= trees[i][j][k]) {
					nutrient[i][j] -= trees[i][j][k];
					new_tree.push_back(trees[i][j][k] + 1);
					if ((trees[i][j][k] + 1) % 5 == 0)
						breed[i][j]++;
				}
				else 
					die[i][j].push_back(trees[i][j][k]);
					
			}
			trees[i][j] = new_tree;
		}
	}
}

void summer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0, sz = die[i][j].size(); k < sz; k++)
				nutrient[i][j] += die[i][j][k] / 2;
			die[i][j] = {};
		}
	}
}

void fall() {
	int ni, nj;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (breed[i][j] == 0)	continue;

			for (int d = 0; d < 8; d++) {
				ni = i + di[d];
				nj = j + dj[d];
				
				if (ni<1 || ni > N || nj < 1 || nj>N)
					continue;

				for (int k = 0; k < breed[i][j]; k++)
					trees[ni][nj].push_back(1);
			}

			breed[i][j] = 0;
		}
	}

}

void winter() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			nutrient[i][j] += S2D2[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S2D2[i][j];
			nutrient[i][j] = 5;
		}
	}
	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int k = 0; k < K; k++) {
		spring();
		summer();
		fall();
		winter();
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result += trees[i][j].size();
		}
	}

	cout << result;

	return 0;
}