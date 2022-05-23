#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	int n;
	string s;
	char input;
	while (T--) {
		cin >> n;
		cin >> s;
		for (int i = 0; i < n - 1; i++) {
			cin >> input;
			if (input <= s[0])	s = input + s;
			else	s = s + input;
		}
		cout << s << "\n";
	}
	return 0;
}