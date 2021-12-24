// next_permutation
// next_permuation은 인자를 다음 순열로 바꾸고 true 반환,
// 다음 순열이 원래 순열보다 작다면 false 반환

// 만약 12345 에 대해 계속 next_permuation을 수행하면
// 12354, 12435, ... 계속 true를 반환하다가 54321 에서 12345로 바뀐 뒤 false 가 반환됨

// 즉, while(next_permuation(arr)) 을 수행하면 arr엔 결과적으로 맨 첫 번째 순열이 저장되어 있음에 유의

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