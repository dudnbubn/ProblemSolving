#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, M, K;
int di[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Fireball {
	int r;
	int c;
	int m;
	int s;
	int d;
	Fireball(int r, int c, int m, int s, int d) {
		this->r = r;
		this->c = c;
		this->m = m;
		this->s = s;
		this->d = d;
	}
};

class Info {
public:
	int m_sum;
	int s_sum;
	int fb_cnt;
	int d;
	Info() {
		this->m_sum = 0;
		this->s_sum = 0;
		this->fb_cnt = 0;
		this->d = 0;
	}

	void clear() {
		m_sum = 0;
		s_sum = 0;
		fb_cnt = 0;
		d = 0;
	}
};

queue<Fireball*> q;
Info* board[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Info* new_info = new Info();
			board[i][j] = new_info;
		}
	}
			
	int r, c, m, s, d;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		Fireball* new_fb = new Fireball(r - 1, c - 1, m, s, d);
		q.push(new_fb);
	}

	while (K--) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j]->clear();

		Fireball* cur = new Fireball(0, 0, 0, 0, 0);
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			cur->r = (cur->r + (di[cur->d] * cur->s) + 1000 * N) % N;
			cur->c = (cur->c + (dj[cur->d] * cur->s) + 1000 * N) % N;
			if (board[cur->r][cur->c]->fb_cnt == 0) {
				board[cur->r][cur->c]->m_sum = cur->m;
				board[cur->r][cur->c]->s_sum = cur->s;
				board[cur->r][cur->c]->fb_cnt = 1;
				board[cur->r][cur->c]->d = cur->d;
			}
			else {
				board[cur->r][cur->c]->m_sum += cur->m;
				board[cur->r][cur->c]->s_sum += cur->s;
				board[cur->r][cur->c]->fb_cnt++;
				if (board[cur->r][cur->c]->d != -1) {
					if (board[cur->r][cur->c]->d % 2 != cur->d % 2)
						board[cur->r][cur->c]->d = -1;
				}
			}
		}
		Fireball* temp;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j]->fb_cnt == 1) {
					temp = new Fireball(i, j, board[i][j]->m_sum, board[i][j]->s_sum, board[i][j]->d);
					q.push(temp);
					board[i][j]->clear();
				}
				else if (board[i][j]->fb_cnt > 1) {
					if (board[i][j]->m_sum / 5 == 0)	continue;
					if (board[i][j]->d == -1) {
						for (int dir = 1; dir < 8; dir += 2) {
							temp = new Fireball(i, j, board[i][j]->m_sum / 5, board[i][j]->s_sum / board[i][j]->fb_cnt, dir);
							q.push(temp);
						}
					}
					else {
						for (int dir = 0; dir < 8; dir += 2) {
							temp = new Fireball(i, j, board[i][j]->m_sum / 5, board[i][j]->s_sum / board[i][j]->fb_cnt, dir);
							q.push(temp);
						}
					}
					board[i][j]->clear();
				}
			}
		}
	}
	int result = 0;
	while (!q.empty()) {
		result += q.front()->m;
		q.pop();
	}
	cout << result;
	return 0;
}