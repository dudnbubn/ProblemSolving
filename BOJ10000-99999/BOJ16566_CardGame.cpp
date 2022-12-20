#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int cards[4000000];
bool visited[4000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)	cin >> cards[i];

	sort(cards, cards + M);

	int chulsu, index;
	for (int i = 0; i < K; i++) {
		cin >> chulsu;

		index = upper_bound(cards, cards + M, chulsu) - cards;

		while (visited[index])
			index++;

		visited[index] = true;
		cout << cards[index] << "\n";
	}
	return 0;
}