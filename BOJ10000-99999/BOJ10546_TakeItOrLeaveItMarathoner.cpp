#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

int main() {
	int n;
	cin >> n;
	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;
		if (um.find(name) == um.end())	um[name] = 1;
		else	um[name]++;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> name;
		um[name]--;
	}
	
	for (pair<string, int> psi : um) {
		if (psi.second) {
			cout << psi.first;
			return 0;
		}
	}
}