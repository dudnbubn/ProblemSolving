// key point : DFA (Deterministic Finite Automata)

#include <iostream>
using namespace std;

int p[10][2];

bool DFA(string s) {
	int index = 1;
	for (int i = 0; i < s.size(); i++) {
		index = p[index][s[i] - '0'];
	}
	if (index == 5 || index == 7 || index == 8)
		return true;
	else
		return false;
}

int main() {
	string s;
	cin >> s;
	p[1][0] = 6;	p[1][1] = 2;
	p[2][0] = 3;	p[2][1] = -1;
	p[3][0] = 4;	p[3][1] = -1;
	p[4][0] = 4;	p[4][1] = 5;
	p[5][0] = 6;	p[5][1] = 8;
	p[6][0] = -1;	p[6][1] = 7;
	p[7][0] = 6;	p[7][1] = 2;
	p[8][0] = 9;	p[8][1] = 8;
	p[9][0] = 4;	p[9][1] = 7;

	if (DFA(s))	cout << "SUBMARINE";
	else	cout << "NOISE";

	return 0;
	
}