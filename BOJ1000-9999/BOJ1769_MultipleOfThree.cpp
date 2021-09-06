#include <iostream>
#include <string>
using namespace std;

string s;
int cnt = 0, change;

int main() {
	cin >> s;
	change = s[0] - '0';
	while (s.size() > 1) {
		cnt++;
		change = 0;
		for (int i = 0; i < s.size(); i++)
			change += s[i] - '0';
		s = to_string(change);
	}
	cout << cnt << "\n";
	if (change % 3 == 0)	cout << "YES";
	else	cout << "NO";
	return 0;
}