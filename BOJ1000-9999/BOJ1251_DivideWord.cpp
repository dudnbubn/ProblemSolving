// Brute Force

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, w1, w2, w3, cur;
	string min = "";
	for (int i = 0; i < 50; i++)	min += 'z';

	cin >> s;

	for (int i = 1; i <= s.size() - 2; i++) {
		for (int j = 1; j <= s.size() - 1 - i; j++) {
			cur = "";
			w1 = s.substr(0, i);
			w2 = s.substr(i, j);
			w3 = s.substr(i + j);
			
			for (int idx = w1.size() - 1; idx >= 0; idx--) cur += w1[idx];
			for (int idx = w2.size() - 1; idx >= 0; idx--) cur += w2[idx];
			for (int idx = w3.size() - 1; idx >= 0; idx--) cur += w3[idx];
			
			if (min > cur)	min = cur;
		}
	}
	cout << min;
	return 0;
}