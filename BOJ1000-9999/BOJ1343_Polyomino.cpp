// 예외처리를 꼼꼼히 해주어야 한다.
// line 17 의 조건을 안해주었더니 100 % 에서 틀렸다고 나왔다..

#include <iostream>
using namespace std;

string arr[501];
string s;
int index = 0;

int main() {
	cin >> s;
	if (s.size() == 0)
		return 0;
	else if (s.size() == 1) {
		if (s == "X")	cout << -1;
		else	cout << '.';
	}
	else {
		arr[index] = s[0];
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1])	arr[index] = arr[index] + s[i];
			else {
				if (arr[index][0] == 'X') {
					int sz = arr[index].size();
					if (sz % 2 == 1) {
						cout << -1;
						return 0;
					}
					if (sz >= 4) {
						arr[index] = "";
						for (int i = 0; i < sz / 4; i++)
							arr[index] += "AAAA";
						for (int i = 0; i < (sz % 4) / 2; i++)
							arr[index] += "BB";
					}
					else 
						arr[index] = "BB";
					
				}
				index++;
				arr[index] = s[i];
			}
		}
		if (arr[index][0] == 'X') {
			int sz = arr[index].size();
			if (sz % 2 == 1) {
				cout << -1;
				return 0;
			}
			if (sz >= 4) {
				arr[index] = "";
				for (int i = 0; i < sz / 4; i++)
					arr[index] += "AAAA";
				for (int i = 0; i < (sz % 4) / 2; i++)
					arr[index] += "BB";
			}
			else
				arr[index] = "BB";
		}
		for (int i = 0; i <= index; i++)
			cout << arr[i];
	}
	return 0;
}