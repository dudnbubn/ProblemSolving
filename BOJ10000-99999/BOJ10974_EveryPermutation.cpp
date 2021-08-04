#include <iostream>
using namespace std;

int n;
int arr[9] = { 0, };
bool visited[9] = { 0, };
int answer[9];

void DFS(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			answer[k] = i;
			DFS(k + 1);
			visited[i] = false;
		}
	}
}
int main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	DFS(0);
	
	return 0;
}