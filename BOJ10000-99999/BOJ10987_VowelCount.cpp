
#include <iostream>
using namespace std;
int r;
int main(){
	string s;
	cin >> s;
	for (char c : s)
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			r++;
	cout << r;
}