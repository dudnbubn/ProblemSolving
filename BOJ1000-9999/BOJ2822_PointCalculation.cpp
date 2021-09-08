#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
pii score[8];

bool compare_first(pii a, pii b) {
	return a.first > b.first;
}
bool compare_second(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> score[i].first;
		score[i].second = i;
	}
	sort(score, score + 8, compare_first);
	sort(score, score + 5, compare_second);
	int tot = 0;
	for (int i = 0; i < 5; i++)	tot += score[i].first;
	cout << tot << "\n";
	for (int i = 0; i < 5; i++)	cout << score[i].second + 1 << " ";
	return 0;
}