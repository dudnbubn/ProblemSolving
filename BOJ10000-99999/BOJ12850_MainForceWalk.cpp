#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define MOD 1'000'000'007

unordered_map<int, vector<vector<int>>> um;	// distance, from to

long long recur(int D, int from, int to) {
	if (um.find(D) != um.end() && um[D][from][to] != -1) {
		return um[D][from][to];
	}

	if (um.find(D) == um.end()) {
		um[D] = {
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		};
	}

	long long result = 0;
	int half = D / 2;
	for (int i = 0; i < 8; i++) {
		result = (result + recur(half, from, i) * recur(D - half, i, to)) % MOD;
	}
	
	return um[D][from][to] = result;
}

int main() {
	int D;
	cin >> D;
	
	um[1] = {
		{0, 1, 1, 0, 0, 0, 0, 0},
		{1, 0, 1, 1, 0, 0, 0, 0},
		{1, 1, 0, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 1, 0 ,0},
		{0, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 1, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 1, 0} 
	};
	
	cout << recur(D, 0, 0);
	return 0;
}