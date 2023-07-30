#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> us;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;

	int card;
	while (N--) {
		cin >> card;
		us.insert(card);
	}

	cin >> M;
	while (M--) {
		cin >> card;
		cout << (us.find(card) == us.end() ? "0 " : "1 ");
	}
}