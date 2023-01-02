#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define MOD 1'000'000'007
int T, N, D, M;

unordered_map<int, vector<vector<int>>> um[101];

int insert(int t, int d, int from, int to, int cnt) {
	if (um[t].find(d) == um[t].end()) {
		vector<vector<int>> v;
		for (int i = 0; i <= N; i++) {
			vector<int> temp;
			for (int j = 0; j <= N; j++)
				temp.push_back(-1);
			v.push_back(temp);
		}
		um[t][d] = v;
	}
	return um[t][d][from][to] = cnt;
}

// t : 경로, d : 시간길이, from : 출발지, to : 도착지
long long get_case_count(int t, int d, int from, int to) {
	if ((um[t].find(d) != um[t].end()) && um[t][d][from][to] != -1) 
		return um[t][d][from][to];

	if (d == 1) {
		if (um[t].find(1) != um[t].end() && um[t][1][from][to] > 0)	return um[t][1][from][to];
		else	return 0;
	}

	int result = 0;
	int half = d / 2;
	int middle_t = (t + half - 1) % T + 1;
	
	for (int i = 1; i <= N; i++) {
		result = (result + get_case_count(t, half, from, i) * get_case_count(middle_t, d - half, i, to)) % MOD;
	}
	return insert(t, d, from, to, result);
}

int main() {
	cin >> T >> N >> D;

	int a, b, c;
	for (int t = 1; t <= T; t++) {
		cin >> M;
		for (int m = 0; m < M; m++) {
			cin >> a >> b >> c;
			insert(t, 1, a, b, c);
		}
	}

	if (D == 0) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				cout << "0 ";
			cout << "\n";
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << get_case_count(1, D, i, j) << " ";
		cout << "\n";
	}
	return 0;
}