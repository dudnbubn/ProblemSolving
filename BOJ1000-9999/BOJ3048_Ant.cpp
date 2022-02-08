#include <iostream>
#include <map>
#include <vector>

using namespace std;
map<char, int> dir;
string s = "";

int main() {
	int n, m;
	cin >> n >> m;
	char input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		dir[input] = 1;
		s = input + s;
	}
	for (int i = 0; i < m; i++) {
		cin >> input;
		dir[input] = -1;
		s = s + input;
	}

	int t;
	cin >> t;
	vector<int> swap;
	char temp;
	while (t--) {
		swap.clear();
		for (int i = 0; i < s.size() - 1; i++) {
			if (dir[s[i]] == 1 && dir[s[i + 1]] == -1)
				swap.push_back(i);
		}
		for (int i = 0; i < swap.size(); i++) {
			temp = s[swap[i]];
			s[swap[i]] = s[swap[i] + 1];
			s[swap[i] + 1] = temp;
		}
	}
	cout << s;
	return 0;
}