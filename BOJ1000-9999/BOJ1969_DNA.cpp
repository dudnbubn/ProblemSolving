#include <iostream>
using namespace std;

int dna[50][4] = { 0, };
int n, m;
string s;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'A')	dna[j][0]++;
			else if (s[j] == 'C')	dna[j][1]++;
			else if (s[j] == 'G')	dna[j][2]++;
			else if (s[j] == 'T')	dna[j][3]++;
		}
	}
	int hd = 0, max = 0, max_idx = 0;
	for (int i = 0; i < m; i++) {
		max = 0;
		max_idx = 0;
		for (int j = 0; j < 4; j++) {
			if (max < dna[i][j]) {
				max = dna[i][j];
				max_idx = j;
			}
		}
		hd += (n - max);
		if (max_idx == 0)	cout << 'A';
		else if (max_idx == 1)	cout << 'C';
		else if (max_idx == 2)	cout << 'G';
		else if (max_idx == 3)	cout << 'T';
	}
	cout << "\n";
	cout << hd;
	return 0;
}