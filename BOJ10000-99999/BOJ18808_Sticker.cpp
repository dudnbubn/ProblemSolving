#include <iostream>

using namespace std;

int N, M, K;
int sticker[100][10][10][4];
int R[100], C[100];

void brute(int k, int laptop[][40]) {
	if (k == K) {
		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (laptop[i][j] == 1)	result++;
			}
		}
		cout << result;
		exit(0);
	}
	int rk, ck;
	
	bool flag;
	
	for (int d = 0; d < 4; d++) {
		if (d % 2 == 0) {
			rk = R[k];
			ck = C[k];
		}
		else {
			rk = C[k];
			ck = R[k];
		}
		for (int i = 0; i <= N - rk; i++) {
			for (int j = 0; j <= M - ck; j++) {
				flag = true;
						
				for (int r = 0; r < rk; r++) {
					for (int c = 0; c < ck; c++) {
						if (laptop[i + r][j + c] == 1 && sticker[k][r][c][d] == 1)
							flag = false;

						if (!flag)	break;
					}
					if (!flag)	break;
				}
				if (!flag)	continue;
				int temp[40][40];
				for (int n = 0; n < N; n++)
					for (int m = 0; m < M; m++)
						temp[n][m] = laptop[n][m];

				for (int r = 0; r < rk; r++)
					for (int c = 0; c < ck; c++)
						if (temp[i + r][j + c] == 1 || sticker[k][r][c][d] == 1)
							temp[i + r][j + c] = 1;
						else 
							temp[i + r][j + c] = 0;
				brute(k + 1, temp);
			}
		}
	}
	int temp[40][40];
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			temp[n][m] = laptop[n][m];
	brute(k + 1, temp);
}

void rotate(int k, int index) {
	int next = index + 1;
	int rk, ck;
	if (index % 2 == 1) {
		rk = R[k];
		ck = C[k];
	}
	else {
		rk = C[k];
		ck = R[k];
	}
	for (int r = 0; r < rk; r++) {
		for (int c = 0; c < ck; c++) {
			sticker[k][r][c][next] = sticker[k][ck - c - 1][r][index];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		cin >> R[k] >> C[k];
		for (int r = 0; r < R[k]; r++) {
			for (int c = 0; c < C[k]; c++)
				cin >> sticker[k][r][c][0];
		}
		for (int i = 0; i < 3; i++)	rotate(k, i);
	}

	
	int laptop[40][40];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			laptop[i][j] = 0;
	brute(0, laptop);

	return 0;
}