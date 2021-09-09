#include <iostream>
#include <map>
using namespace std;

string numToName[100001];
map<string, int> nameToNum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> numToName[i];
		nameToNum[numToName[i]] = i;
	}
	string question;
	for (int i = 0; i < m; i++) {
		cin >> question;
		if ('0' <= question[0] && question[0] <= '9') {
			num = 0;
			for (int j = 0; j < question.size(); j++) {
				num *= 10;
				num += question[j] - '0';
			}
			cout << numToName[num] << "\n";
		}
		else
			cout << nameToNum[question] << "\n";
	}
	return 0;
}