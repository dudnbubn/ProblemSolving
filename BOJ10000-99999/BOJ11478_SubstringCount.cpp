#include <iostream>
#include <set>

using namespace std;

set<string> str_set;

int main() {
	string s;
	cin >> s;
	string temp;
	for (int i = 0; i < s.size(); i++) {
		temp = "";
		for (int j = i; j < s.size(); j++) {
			temp = temp + s[j];
			str_set.insert(temp);
		}
	}
	cout << str_set.size();
	return 0;
}