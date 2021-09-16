#include <iostream>
#include <set>
using namespace std;

set<string> strings;

int main() {
	int n, m;
	string input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		strings.insert(input);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (strings.find(input) != strings.end())
			cnt++;
	}
	cout << cnt;
	return 0;
}