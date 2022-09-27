#include <iostream>
#include <algorithm>

using namespace std;

int result;
int di[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

typedef pair<pair<int, int>, int> Fish;

void swap(int a, int b, Fish arr[]) {
    pair<int, int> pos = arr[a].first;
    arr[a].first = arr[b].first;
    arr[b].first = pos;
}

void recur(int fi, int fj, int sum, Fish fishes[], int board[][4]) {
    int si = fi, sj = fj;
    int sd = fishes[board[si][sj]].second;
    sum += board[si][sj];
    fishes[board[fi][fj]].second = -1;
    board[fi][fj] = 0;


    int ci, cj, cd, ni, nj, nd;
    for (int i = 1; i <= 16; i++) {
        ci = fishes[i].first.first;
        cj = fishes[i].first.second;
        cd = fishes[i].second;
        if (cd == -1)  continue;

        for (int j = 0; j < 8; j++) {
            nd = (cd + j) % 8;
            ni = ci + di[nd];
            nj = cj + dj[nd];

            if (0 <= ni && ni < 4 && 0 <= nj && nj < 4 && (si != ni || sj != nj)) {
                int next_fish = board[ni][nj];
                fishes[next_fish].first = {ci, cj};
                fishes[i] = {{ni, nj}, nd};
                board[ni][nj] = i;
                board[ci][cj] = next_fish;
                break;
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= 3; i++) {
        ni = si + di[sd] * i;
        nj = sj + dj[sd] * i;
        if (ni < 0 || nj < 0 || ni >= 4 || nj >= 4)  break;

        if (board[ni][nj] > 0) {
            flag = true;
            Fish temp_fishes[17];
            int temp_board[4][4];
            for (int i = 1; i <= 16; i++) temp_fishes[i] = fishes[i];
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++)
                    temp_board[i][j] = board[i][j];
            }

            recur(ni, nj, sum, temp_fishes, temp_board);
        }
    }
    if (!flag) {
        result = result > sum ? result : sum;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Fish fishes[17];
    int board[4][4];
    int a, b;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            fishes[a].first = { i, j };
            fishes[a].second = b - 1;
            board[i][j] = a;
        }
    }

    recur(0, 0, 0, fishes, board);
    cout << result;

    return 0;
}