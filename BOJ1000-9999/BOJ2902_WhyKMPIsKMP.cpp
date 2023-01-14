#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (char c : s) {
		if ('A' <= c && c <= 'Z')
			cout << c;
	}
}