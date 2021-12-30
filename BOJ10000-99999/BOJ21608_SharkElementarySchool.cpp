#include <iostream>
using namespace std;

int n;
int board[21][21] = { 0, };
int seq[401];
int arr[401][4];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

int main() {
	cin >> n;
	for (int i = 1; i <= n * n; i++) {
		cin >> seq[i];
		for (int j = 0; j < 4; j++)
			cin >> arr[seq[i]][j];
	}

	for (int s = 1; s <= n * n; s++) {
		int frnd = 0, opning = 0;
		int fin_i = 0, fin_j = 0;
		for (int i = 1; i <= n; i++) {
			if (fin_i != 0) break;
			for (int j = 1; j <= n; j++) {
				if (board[i][j] == 0) {
					fin_i = i;
					fin_j = j;
					break;
				}
			}
		}
		int temp_frnd, temp_opning;
		int next_i, next_j;
		//cout << seq[s] << " 학생에 대해\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] != 0)	continue;
				//cout << "\t" << i << ", " << j << " 자리일 때\n";
				temp_frnd = 0;	temp_opning = 0;
				for (int k = 0; k < 4; k++) {
					next_i = i + di[k];
					next_j = j + dj[k];
					if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
						continue;

					if (board[next_i][next_j] == 0) {
						//cout << "\t" << next_i << ", " << next_j << " 자리 공석\n";
						temp_opning++;
					}
					else {
						for (int f = 0; f < 4; f++) {
							if (board[next_i][next_j] == arr[seq[s]][f]) {
								temp_frnd++;
								break;
							}
						}
					}
				}
				if (temp_frnd > frnd) {
					frnd = temp_frnd;
					opning = temp_opning;
					fin_i = i;
					fin_j = j;
				}
				else if (temp_frnd == frnd) {
					if (temp_opning > opning) {
						opning = temp_opning;
						fin_i = i;
						fin_j = j;
					}
				}
			}
		}
		board[fin_i][fin_j] = seq[s];
	}

	//cout << "좌석 배치도\n";
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++)
	//		cout << board[i][j] << " ";
	//	cout << "\n";
	//}
	//cout << "\n";

	int result = 0;
	int next_i, next_j, cnt;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//cout << i << ", " << j << " 에 앉은 " << board[i][j] << " 학생에 대해\n";
			cnt = 0;
			for (int k = 0; k < 4; k++) {
				next_i = i + di[k];
				next_j = j + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
					continue;

				//cout << "\t" << next_i << ", " << next_j << " 에 앉은 친구 " << board[next_i][next_j] << "는? ";
				for (int f = 0; f < 4; f++) {
					if (board[next_i][next_j] == arr[board[i][j]][f]) {
						//cout << board[i][j] << " 학생의 친구이다.";
						cnt++;
						break;
					}
				}
				//cout << "\n";
			}
			switch (cnt) {
			case 1:		result += 1;		break;
			case 2:		result += 10;		break;
			case 3:		result += 100;		break;
			case 4:		result += 1000;	break;
			}
		}
	}
	cout << result;
	return 0;
}