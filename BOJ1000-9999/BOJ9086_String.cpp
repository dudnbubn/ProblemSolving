#include <iostream>
using namespace std;
int T;
string s;
int main() {
	cin >> T;
	while (T--) {
		cin >> s;
		cout << s[0] << s[s.size() - 1] << "\n";
	}
}