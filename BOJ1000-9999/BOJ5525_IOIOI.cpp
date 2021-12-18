// KMP algorithm

#include <iostream>
using namespace std;

int n, m;
string s;
int f[1000001];

void Failure(string p) {
	f[0] = 0;
	int i = 1, j = 0;
	while (i < p.size()) {
		if (p[i] == p[j]) {
			f[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			f[i] = 0;
			j = f[j - 1];
		}
		else
			i++;
	}
}

int KMP(string t, string p) {
	int cnt = 0;
	int i = 0, j = 0;
	while (i < t.size()) {
		if (t[i] == p[j]) {
			if (j == p.size() - 1) {
				cnt++;
				j = f[j - 1];
			}
			else {
				i++;
				j++;
			}
		}
		else if (j > 0)
			j = f[j - 1];
		else
			i++;
	}
	return cnt;
}

int main() {	
	cin >> n >> m >> s;
	string p = "I";
	for (int i = 0; i < n; i++)	p += "OI";
	Failure(p);
	cout << KMP(s, p);

	return 0;
}