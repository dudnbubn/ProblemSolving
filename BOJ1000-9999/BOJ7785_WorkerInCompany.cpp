#include <iostream>
#include <map>
using namespace std;

map<string, string, greater<string>> m;
map<string, string>::iterator iter;
int n;

int main() {
	cin >> n;
	string name, state;
	for (int i = 0; i < n; i++) {
		cin >> name >> state;
		m[name] = state;
	}
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == "enter")	cout << iter->first << "\n";
	}
	return 0;
}