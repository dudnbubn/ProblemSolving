#include <iostream>
#include <map>
using namespace std;

map<string, string> mss;
map<string, string>::iterator iter;
string addr, pwd;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> addr >> pwd;
		mss[addr] = pwd;
	}
	for (int i = 0; i < m; i++) {
		cin >> addr;
		cout << mss.find(addr)->second << "\n";
	}
}