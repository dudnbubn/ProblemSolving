#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string left, right, input;
	cin >> n;
	cin >> input;
	int index = input.find("*");
	left = input.substr(0, index);
	right = input.substr(index + 1);
	int lsz = left.size(), rsz = right.size();
	cin.clear();
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input.size() < lsz + rsz) {
			cout << "NE\n";
			continue;
		}
		if (input.substr(0, lsz) != left || input.substr(input.size() - rsz) != right) {
			cout << "NE\n";
			continue;
		}
		if (input.find(left) != string::npos && input.find(right) != string::npos) {
			index = input.find(left);
			if (input.substr(index + lsz).find(right) != string::npos) {
				cout << "DA\n";
			}
			else {
				cout << "NE\n";
			}
				
		}
		else
			cout << "NE\n";
	}
	return 0;
}