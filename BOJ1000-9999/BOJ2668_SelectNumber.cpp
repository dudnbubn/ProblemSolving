#include <iostream>
using namespace std;

int n;
int arr[101];
int visited[101] = { 0, };

void Cycle(int start, int num) {
	if (visited[num] > 0)	return; 

	visited[num] = 1;

	if (start == num) {
		for (int i = 1; i <= n; i++)
			if (visited[i] == 1)	visited[i] = 2;
	}

	Cycle(start, arr[num]);
	if (visited[num] == 1)	visited[num] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	for (int i = 1; i <= n; i++)	Cycle(i, arr[i]);

	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (visited[i] == 2)	cnt++;
	
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++)
		if (visited[i] == 2)
			cout << i << "\n";

	return 0;
}