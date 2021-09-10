#include <iostream>
#include <cmath>
using namespace std;

int n, cnt = 0;
int word[26] = { 0, };
int test[26];
string origin, unorigin;

int main() {
	cin >> n;
	cin >> origin;
	for (int i = 0; i < origin.size(); i++)	word[origin[i] - 'A']++;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 26; j++)	test[j] = 0;
		cin >> unorigin;
		for (int j = 0; j < unorigin.size(); j++)	test[unorigin[j] - 'A']++;

		int error = 0, cross = 0;
		for (int j = 0; j < 26; j++) {
			if (word[j] != test[j]) {
				error += abs(word[j] - test[j]);
				cross += (word[j] - test[j]);
			}
		}
		if (error == 0 || error == 1)	cnt++;
		else if (error == 2 && cross == 0) cnt++;
		
	}
	cout << cnt;
	return 0;
}