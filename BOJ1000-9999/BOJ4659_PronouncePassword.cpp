#include <iostream>
using namespace std;

bool isVowel(char a) {
	switch (a) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	while (s != "end") {
		bool vowel = false;
		bool excpt = false;
		bool conti = false;
		for (int i = 0; i < s.size(); i++) {
			if (isVowel(s[i]))
				vowel = true;
			if (i > 0) {
				if (s[i] == s[i - 1]) {
					if (s[i] != 'e' && s[i] != 'o') {
						excpt = true;
						break;
					}
				}
			}
			if (i > 1) {
				if (isVowel(s[i]) == isVowel(s[i - 1]) && isVowel(s[i - 1]) == isVowel(s[i - 2])) {
					conti = true;
					break;
				}
			}
		}
		if (!vowel || excpt || conti)
			cout << "<" << s << "> is not acceptable.\n";
		else
			cout << "<" << s << "> is acceptable.\n";
		cin >> s;
	}
}