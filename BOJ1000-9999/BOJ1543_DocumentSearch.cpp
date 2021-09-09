#include <iostream>
#include <string>
using namespace std;

int main() {
	string doc, word;
	int cnt = 0;
	getline(cin, doc);
	getline(cin, word);
	for (int i = 0; i < doc.size(); i++) {
		if (doc.substr(i, word.size()) == word) {
			cnt++;
			i += (word.size() - 1);
		}
	}
	cout << cnt;
	return 0;
}