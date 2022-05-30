#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> ext_map;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		string extension = input.substr(input.find(".") + 1);
		
		if (ext_map.find(extension) == ext_map.end())	ext_map[extension] = 1;
		else	ext_map[extension]++;
	}

	for (pair<string, int> psi : ext_map)
		cout << psi.first << " " << psi.second << "\n";
	return 0;
}