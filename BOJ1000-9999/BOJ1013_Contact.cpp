// key point : DFA(Deterministic Finite Automata)

#include <iostream>
using namespace std;

int status[100][2];

bool isPattern(string s) {
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		cur = status[cur][s[i] - '0'];
		if (cur == 99)
			return false;
	}
	if (cur == 2 || cur == 6 || cur == 7)	return true;
	else	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	string s;

	status[0][0] = 1;
	status[0][1] = 3;
	status[1][0] = 99;
	status[1][1] = 2;
	status[2][0] = 1;
	status[2][1] = 3;
	status[3][0] = 4;
	status[3][1] = 99;
	status[4][0] = 5;
	status[4][1] = 99;
	status[5][0] = 5;
	status[5][1] = 6;
	status[6][0] = 1;
	status[6][1] = 7;
	status[7][0] = 5;
	status[7][1] = 7;

	while (t--) {
		cin >> s;
		if (isPattern(s))	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}