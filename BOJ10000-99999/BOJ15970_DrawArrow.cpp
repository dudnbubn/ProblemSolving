#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n, location, color, result = 0;
vector<int> cur;
map<int, vector<int>> mv;
map<int, vector<int>>::iterator iter;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> location >> color;
		if (mv.find(color) == mv.end()) {
			vector<int> temp;
			temp.push_back(location);
			mv[color] = temp;
		}
		else {
			mv[color].push_back(location);
		}
	}
	for (iter = mv.begin(); iter != mv.end(); iter++) {
		cur = iter->second;
		sort(cur.begin(), cur.end());
		for (int i = 0; i < cur.size(); i++) {
			if (i == 0)		result += cur[i + 1] - cur[i];
			else if (i == cur.size() - 1)	result += cur[i] - cur[i - 1];
			else {
				result += min(cur[i] - cur[i - 1], cur[i + 1] - cur[i]);
			}
		}
	}
	cout << result;
	return 0;
}