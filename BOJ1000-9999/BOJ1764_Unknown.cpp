#include <iostream>
#include <map>
using namespace std;

int n, m, cnt = 0;
map<string, int> roll;
map<string, int>::iterator iter;
string name;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> name;
		if (roll.find(name) == roll.end())	roll[name] = 1;
		else {
			roll[name]++;
			if (roll[name] == 2)	cnt++;
		}
	}
	cout << cnt << "\n";
	for (iter = roll.begin(); iter != roll.end(); iter++)
		if (iter->second == 2)
			cout << iter->first << "\n";
	return 0;
}