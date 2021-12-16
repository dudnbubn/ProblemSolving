#include <iostream>
using namespace std;

bool flag;

int Palindrome(string s) {
	int start = 0;
	int end = s.size() - 1;

	while (start < end) {
		if (s[start] == s[end]) {
			start++;
			end--;
		}
		else {
			if (!flag) {
				flag = true;
				int left = Palindrome(s.substr(start + 1, end - start));
				int right = Palindrome(s.substr(start, end - start));
				if (left == 0 || right == 0)
					return 1;
			}
			else
				return 2;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		flag = false;
		cout << Palindrome(s) << "\n";
	}
	return 0;
}