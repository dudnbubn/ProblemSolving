#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M;
int A[1000];
int B[1000];

unordered_map<int, int> subsumA, subsumB;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int client;
	cin >> client;

	int totA = 0, totB = 0;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		cin >> A[i];
		totA += A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		totB += B[i];
	}

	for (int i = 0; i < M; i++) {
		int save = 0;
		for (int j = 0; j < M; j++) {
			save += A[(i + j) % M];
			int temp = save;
			if (subsumA.find(temp) == subsumA.end()) 
				subsumA[temp] = 1;
			else 
				subsumA[temp]++;
		}
	}

	for (int i = 0; i < N; i++) {
		int save = 0;
		for (int j = 0; j < N; j++) {
			save += B[(i + j) % N];
			int temp = save;
			if (subsumB.find(temp) == subsumB.end())
				subsumB[temp] = 1;
			else	
				subsumB[temp]++;
		}
	}
	subsumA[totA] -= M - 1;
	subsumB[totB] -= N - 1;

	int result = 0;
	if (subsumA.find(client) != subsumA.end())	result += subsumA[client];
	if (subsumB.find(client) != subsumB.end())	result += subsumB[client];

	for (auto iter : subsumA) {
		if (subsumB.find(client - iter.first) != subsumB.end()) {
			result += iter.second * subsumB[client - iter.first];
		}
	}

	cout << result;

	return 0;
}