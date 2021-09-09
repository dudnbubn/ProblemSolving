#include <iostream>
using namespace std;

int alphabet[26] = { 0, };

int main() {
	string name, palindrome_f = "", palindrome_b = "";
	int cnt = 0, index = 0;
	cin >> name;
	for (int i = 0; i < name.size(); i++) alphabet[name[i] - 'A']++;
	for (int i = 0; i < 26; i++)
		if (alphabet[i] % 2 == 1) {
			cnt++;
			index = i;
		}
	
	if (cnt > 1)	cout << "I'm Sorry Hansoo";
	else {
		for (int i = 0; i < 26; i++) 
			for (int j = 0; j < alphabet[i] / 2; j++) {
				palindrome_f = palindrome_f + (char)(i + 'A');
				palindrome_b = (char)(i + 'A') + palindrome_b;
			}
		if(cnt==0)	cout << palindrome_f <<  palindrome_b;
		else	cout << palindrome_f << (char)(index + 'A') << palindrome_b;
	}
	return 0;
}