// �������� ���ܸ� �� �� ó�����־�� �Ѵ�. ex) ���ӵ� '_', �� ��, ���� '_', etc..

#include <iostream>
using namespace std;

int main() {
	bool java = true, cpp = true, capital = false;
	string s, answer = "";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			if (!java || i == 0) {
				answer = "Error!";
				break;
			}
			cpp = false;
			answer = answer + '_' + (char)((s[i] - 'A') + 'a');
		}
		else if (s[i] == '_') {
			if (!cpp || i == 0 || i == s.size() - 1 || s[i - 1] == '_') {
				answer = "Error!";
				break;
			}
			java = false;
			capital = true;
		}
		else {
			if (capital) {
				answer += (char)((s[i] - 'a') + 'A');
				capital = false;
			}
			else	answer += s[i];
		}
	}
	cout << answer;
	return 0;
}