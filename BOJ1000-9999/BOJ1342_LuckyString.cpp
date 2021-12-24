// next_permutation
// next_permuation�� ���ڸ� ���� ������ �ٲٰ� true ��ȯ,
// ���� ������ ���� �������� �۴ٸ� false ��ȯ

// ���� 12345 �� ���� ��� next_permuation�� �����ϸ�
// 12354, 12435, ... ��� true�� ��ȯ�ϴٰ� 54321 ���� 12345�� �ٲ� �� false �� ��ȯ��

// ��, while(next_permuation(arr)) �� �����ϸ� arr�� ��������� �� ù ��° ������ ����Ǿ� ������ ����

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int result = 0;
set<string> set_str;
set<string>::iterator iter;

void next_perm(string s) {
	do {
		set_str.insert(s);
	} while (next_permutation(s.begin(), s.end()));
}

bool isLucky(string str) {
	for (int i = 1; i < str.size() - 1; i++)
		if (str[i] == str[i - 1] || str[i] == str[i + 1]) {
			return false;
		}
	return true;
}

int main() {
	string s;
	cin >> s;
	bool visited[26] = { 0, };
	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (!visited[s[i] - 'a'])
			visited[s[i] - 'a'] = true;
		else
			flag = true;
	}
	if (flag) {
		while (next_permutation(s.begin(), s.end()));

		next_perm(s);

		for (iter = set_str.begin(); iter != set_str.end(); iter++)
			if (isLucky(*iter))
				result++;
		cout << result;
	}
	else {
		int result = 1;
		for (int i = 2; i <= s.size(); i++)
			result *= i;
		cout << result;
	}
		
	return 0;
}