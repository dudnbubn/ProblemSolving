#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U' && cnt == 0)	cnt++;
		else if (s[i] == 'C' && (cnt == 1 || cnt == 3))	cnt++;
		else if (s[i] == 'P' && cnt == 2)	cnt++;

		if (cnt == 4)	break;
	}
	if (cnt == 4)	cout << "I love UCPC";
	else	cout << "I hate UCPC";
}