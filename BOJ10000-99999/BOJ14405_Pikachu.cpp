#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string sub = s.substr(i, 2);
		if (sub == "pi" || sub == "ka")	i++;
		else if (sub == "ch") {
			if (i != s.size() - 2 && s[i + 2] == 'u')
				i += 2;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}