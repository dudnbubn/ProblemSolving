#include <iostream>

using namespace std;

int N;
int result;
int price_list[15][15];
bool visited[15][10][1 << 15];

void DFS(int price, int owner, int cnt, int bit) {
	if (visited[owner][price][bit])	return;

	result = result > cnt ? result : cnt;
	visited[owner][price][bit] = true;
	for (int i = 0; i < N; i++) {
		if(i == owner || price_list[owner][i] < price || (bit& (1 << i)))	
			continue;
		
		DFS(price_list[owner][i], i, cnt + 1, (bit | (1 << i)));
	}
}

int main() {
	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++)
			price_list[i][j] = input[j] - '0';
	}
	DFS(0, 0, 1, 1);
	cout << result;
	return 0;
}