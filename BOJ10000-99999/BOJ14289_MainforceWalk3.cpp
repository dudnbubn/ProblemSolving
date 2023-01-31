#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define MOD 1'000'000'007

int N, M;
unordered_map<int, vector<vector<int>>> um;

vector<vector<int>> get_vector(int init) {
	vector<vector<int>> result(N + 1);
	for (int i = 1; i <= N; i++) {
		vector<int> temp(N + 1, init);
		result[i] = temp;
	}
	return result;
}

long long get_case_count(int start, int end, int d) {
	if (d == 1)	return um[d][start][end];
	if (um.find(d) == um.end()) 
		um[d] = get_vector(-1);
	
	if (um[d][start][end] != -1)	return um[d][start][end];

	int half = d / 2;
	long long result = 0;
	for (int i = 1; i <= N; i++) {
		result = (result + (get_case_count(start, i, half) * get_case_count(i, end, d - half)) % MOD) % MOD;
	}

	return um[d][start][end] = result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<int>> v = get_vector(0);
	
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a][b] = v[b][a] = 1;
	}
	um[1] = v;

	int D;
	cin >> D;
	cout << get_case_count(1, 1, D);
	return 0;
}