#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> v;
map<string, bool> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	string str;
	while (t--) {
		v.clear();
		m.clear();

		cin >> str;
		while (str != "goes") {
			v.push_back(str);
			cin >> str;
		}
		for (int i = 0; i < v.size() - 1; i++)
			m[v[i]] = true;

		cin >> str;
		while (str != "the") {
			m[str] = false;
			cin >> str >> str >> str;
		}
		cin >> str >> str;
		for (int i = 0; i < v.size() - 1; i++) {
			if (m[v[i]])	cout << v[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}