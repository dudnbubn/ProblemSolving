#include <iostream>

using namespace std;

int n, m;
int weight[30];
bool visited[31][80001];

void Brute(int k, int value) {
	if (visited[k][value])	return;
	else	visited[k][value] = true;
	if (k == n)	return;
	
	Brute(k + 1, value + weight[k]);
	Brute(k + 1, value - weight[k]);
	Brute(k + 1, value);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> weight[i];

	Brute(0, 40000);

	cin >> m;
	int num;
	bool flag;
	for (int i = 0; i < m; i++) {
		cin >> num;
		flag = false;
		for (int j = 1; j <= n; j++) {
			if (visited[j][40000 + num]) {
				flag = true;
				break;
			}
		}
		if (flag)	cout << "Y ";
		else		cout << "N ";
	}
	return 0;
}