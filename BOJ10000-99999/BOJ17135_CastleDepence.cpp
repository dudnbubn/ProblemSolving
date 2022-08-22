#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, D, result;
int archers[3];
vector<pair<int, int>> enemys;

int depence(vector<pair<int, int>> es) {
	int kill = 0;
	bool killed[225];

	vector<pair<int, int>> temp;
	int d, index = 0, temp_d;
	int tj = 0, ei, ej;

	while (!es.empty()) {
		temp = {};
		for (int i = 0; i < es.size(); i++)		killed[i] = false;

		for (int i = 0; i < 3; i++) {
			d = tj = 1e9;
			index = -1;
			for (int j = 0; j < es.size(); j++) {
				ei = es[j].first;
				ej = es[j].second;
				temp_d = abs(N + 1 - ei) + abs(archers[i] - ej);

				if (temp_d > D)	continue;

				if (temp_d < d) {
					d = temp_d;
					tj = ej;
					index = j;
				}
				else if (temp_d == d && tj > ej) {
					tj = ej;
					index = j;
				}
			}
			if (index != -1)	killed[index] = true;
		}
		for (int i = es.size() - 1; i >= 0; i--) {
			ei = es[i].first;
			ej = es[i].second;

			if (killed[i]) kill++;
			else if (ei != N)
				temp.push_back({ ei + 1, ej });
		}
		es = temp;
	}

	return kill;
}

void comb(int depth, int start) {
	if (depth == 3) {
		vector<pair<int, int>> temp_enemys;
		for (pair<int, int> p : enemys)
			temp_enemys.push_back(p);

		result = max(result, depence(temp_enemys));
		return;
	}

	for (int i = start; i <= M; i++) {
		archers[depth] = i;
		comb(depth + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> D;

	int input;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++) {
			cin >> input;
			if (input == 1)
				enemys.push_back({ i, j });
		}
	}

	comb(0, 1);

	cout << result;

	return 0;
}