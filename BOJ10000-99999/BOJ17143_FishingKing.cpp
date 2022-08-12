//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//struct Shark {
//	int s;
//	int d;
//	int z;
//	Shark(int s, int d, int z) {
//		this->s = s;
//		this->d = d;
//		this->z = z;
//	}
//};
//
//int R, C, M;
//Shark* board[1001][1001];
//Shark* temp[1001][1001];
//int di[5] = { 0, -1, 1, 0, 0 };
//int dj[5] = { 0, 0, 0, 1, -1 };
//
//int opposite(int dir) {
//	if (dir % 2 == 0)	return dir - 1;
//	else				return dir + 1;
//}
//
//int main() {
//	cin >> R >> C >> M;
//	for (int i = 1; i <= R; i++)
//		for (int j = 1; j <= C; j++)
//			board[i][j] = nullptr;
//	
//	int r, c, s, d, z;
//	for (int i = 0; i < M; i++) {
//		cin >> r >> c >> s >> d >> z;
//		if (d <= 2)
//			s = s % ((R - 1) * 2);
//		else
//			s = s % ((C - 1) * 2);
//		board[r][c] = new Shark(s, d, z);
//	}
//
//	int result = 0;
//
//	int fk = 0;
//	while (fk <= C) {
//		// 0. init
//		for (int i = 1; i <= R; i++)
//			for (int j = 1; j <= C; j++)
//				temp[i][j] = nullptr;
//
//		// 1. fishingking move
//		fk++;
//
//		// 2. fishing shark
//		for (int i = 1; i <= R; i++) {
//			if (board[i][fk] == nullptr)	continue;
//
//			result += board[i][fk]->z;
//			board[i][fk] = nullptr;
//			break;
//		}
//
//		// 3. sharks move
//		for (int i = 1; i <= R; i++) {
//			for (int j = 1; j <= C; j++) {
//				if (board[i][j] == nullptr)	continue;
//
//				r = i;
//				c = j;
//				s = board[i][j]->s;
//				d = board[i][j]->d;
//				z = board[i][j]->z;
//
//				int temps = s;
//				if (r == 1 && d == 1)	d = 2;
//				if (r == R && d == 2)	d = 1;
//				if (c == 1 && d == 4)	d = 3;
//				if (c == C && d == 3)	d = 4;
//				while (temps--) {
//					r += di[d];
//					c += dj[d];
//
//					if (r < 1 || r > R || c < 1 || c > C) {
//						d = opposite(d);
//						r += 2 * di[d];
//						c += 2 * dj[d];
//					}
//				}
//				board[i][j]->d = d;
//
//				if (temp[r][c] == nullptr) 
//					temp[r][c] = board[i][j];
//				else if (temp[r][c]->z < board[i][j]->z) 
//					temp[r][c] = board[i][j];
//			}
//		}
//		for (int i = 1; i <= R; i++)
//			for (int j = 1; j <= C; j++)
//				board[i][j] = temp[i][j];
//	}
//
//	cout << result;
//
//	return 0;
//}