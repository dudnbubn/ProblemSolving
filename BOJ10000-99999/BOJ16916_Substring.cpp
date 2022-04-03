#include <iostream>

using namespace std;

int f[1000001];
string s, p;

void Failure() {
	f[0] = 0;
	int i = 1, j = 0;
	while (i < p.size()) {
		if (p[i] == p[j]) {
			f[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
			j = f[j - 1];
		else {
			f[i] = 0;
			i++;
		}
	}
}

void KMP() {
	int i = 0, j = 0;
	while (i < s.size()) {
		if (s[i] == p[j]) {
			if (j == p.size() - 1) {
				cout << 1;
				return;
			}
			i++;
			j++;
		}
		else if (j > 0)
			j = f[j - 1];
		else
			i++;
	}
	cout << 0;
	return;
}

int main() {
	cin >> s >> p;
	Failure();
	KMP();
	return 0;
}