#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

unordered_set<string> us;

string s, t;

void recur(string str) {
	int size = str.size();
	if (size == 0)	return;

	us.insert(str);
	
	if (str[size - 1] == 'A')	recur(str.substr(0, size - 1));
	if (str[size - 1] == 'B') {
		reverse(str.begin(), str.end());
		recur(str.substr(1));
	}
}

int main() {
	cin >> s >> t;
	recur(t);

	cout << (us.find(s) != us.end() ? 1 : 0);
	return 0;
}