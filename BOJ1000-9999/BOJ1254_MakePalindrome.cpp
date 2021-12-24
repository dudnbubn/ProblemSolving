#include <iostream>
using namespace std;

double center(string s) {
	double index = (double)s.size() / 2 - 0.5;
	int comp;
	bool flag;

	while (index < s.size()) {
		comp = index;
		flag = true;
		//cout << "comp : " << comp << ", index : " << index << "\n";
		if (comp == index) {
			for (int i = 1; index + i < s.size(); i++) {
				//cout << index - i << "(" << s[index - i] << "), " << index + i << "(" << s[index + i] << ") 비교\n";
				if (s[index - i] != s[index + i]) {
					flag = false;
					break;
				}
			}
			if (flag)
				return index;
		}
		else {
			for (int i = 0; comp + i + 1 < s.size(); i++) {
				//cout << comp - i << "(" << s[comp - i] << "), " << comp + i + 1 << "(" << s[comp + i + 1] << ") 비교\n";
				if (s[comp - i] != s[comp + i + 1]) {
					flag = false;
					break;
				}
			}
			if (flag)
				return index;
		}
		index += 0.5;
	}
	return -1;
	
}

int main() {
	string s;
	cin >> s;
	double result = center(s);
	if (result == -1)	cout << s.size() * 2 - 1;
	else	cout << result * 2 + 1;
	
	return 0;
}