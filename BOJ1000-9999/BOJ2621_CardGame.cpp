#include <iostream>
#include <algorithm>
using namespace std;

pair<char, int> card[5];
int numbers[10] = { 0, };

bool compare(pair<char, int> a, pair<char, int> b) {
	return a.second < b.second;
}

int main() {
	int maximum = 0;
	bool color = true, straight = true;
	pair<int, int> fir = { 0,0 }, sec = { 0,0 };

	for (int i = 0; i < 5; i++) {
		cin >> card[i].first >> card[i].second;
		numbers[card[i].second]++;
		maximum = max(maximum, card[i].second);
	}
	sort(card, card + 5, compare);
	for (int i = 1; i < 5; i++)
		if (card[i].first != card[i - 1].first)
			color = false;

	for (int i = 1; i < 5; i++)
		if (card[i].second - card[i - 1].second != 1)
			straight = false;

	for (int i = 1; i < 10; i++) {
		if (numbers[i] >= fir.first) {
			sec.first = fir.first;
			sec.second = fir.second;
			fir.first = numbers[i];
			fir.second = i;
		}
		else if (numbers[i] > sec.first) {
			sec.first = numbers[i];
			sec.second = i;
		}
	}
	// rule
	if (color && straight) cout << 900 + maximum;
	else if (fir.first == 4)	cout << 800 + fir.second;
	else if (fir.first == 3 && sec.first == 2) cout << 700 + fir.second * 10 + sec.second;
	else if (color)	cout << 600 + maximum;
	else if (straight)	cout << 500 + maximum;
	else if (fir.first == 3)	cout << 400 + fir.second;
	else if (fir.first == 2 && sec.first == 2)	cout << 300 + fir.second * 10 + sec.second;
	else if (fir.first == 2)	cout << 200 + fir.second;
	else	cout << 100 + maximum;

	return 0;
}