#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
map<string, int>::iterator iter;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, maximum = 0;
	string book, bestseller = "";
	for (int i = 0; i < 50; i++)	bestseller = bestseller + 'z';
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> book;
		if (m.find(book) == m.end())	m[book] = 1;
		else	m[book]++;
	}
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (maximum < iter->second) {
			maximum = iter->second;
			bestseller = iter->first;
		}
	}
	cout << bestseller;
	return 0;
}