#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> b = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int main() {
	string s;
	getline(cin, s);
	int a;
	while (s != "#") {
		a = 0;
		for (char c : s) {
			if (b.find(c) != b.end())
				a++;
		}
		cout << a << "\n";
		getline(cin, s);
	}
}