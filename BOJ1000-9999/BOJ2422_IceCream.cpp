// Brute Force

#include <iostream>
#include <vector>
using namespace std;

bool terrible[201][201] = { 0, };
int n, m, a, b, cnt = 0;
bool visited[201] = { 0, };
vector<int> choice;

void Brute(int k, int prev) {
	if (k == 3) {
		if (!terrible[choice[0]][choice[1]] && !terrible[choice[1]][choice[2]] && !terrible[choice[0]][choice[2]])
			cnt++;
		return;
	}
	for (int i = prev + 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			choice.push_back(i);
			Brute(k + 1, i);
			choice.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		terrible[a][b] = true;
		terrible[b][a] = true;
	}
	Brute(0, 0);
	cout << cnt;
	return 0;
}