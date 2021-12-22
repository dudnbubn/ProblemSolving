#include <iostream>
#include <set>
#include <map>
using namespace std;

map<string, set<string>> mp;
map<string, set<string>>::iterator iter;
set<string> grp;
set<string>::iterator siter;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string grp_name, member;
	int grp_num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		grp.clear();
		cin >> grp_name >> grp_num;
		for (int j = 0; j < grp_num; j++) {
			cin >> member;
			grp.insert(member);
		}
		mp.insert({ grp_name, grp });
	}
	int cmd;
	for (int i = 0; i < m; i++) {
		cin >> member >> cmd;
		if (cmd == 0) {
			for (iter = mp.begin(); iter != mp.end(); iter++) {
				if (iter->first == member) {
					for (siter = iter->second.begin(); siter != iter->second.end(); siter++)
						cout << *siter << "\n";
					break;
				}
			}
		}
		else {
			for (iter = mp.begin(); iter != mp.end(); iter++) {
				if (iter->second.find(member) != iter->second.end()) {
					cout << iter->first << "\n";
					break;
				}
			}
		}
	}
	return 0;
}