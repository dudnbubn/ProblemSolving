#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int H, W;
int board[1001][1001];
int cnt[1001][1001];
int di[8] = {-1,-1,-1,0,1,1,1,0};
int dj[8] = {-1,0,1,1,1,0,-1,-1};

queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    string input;
    for(int i=1;i<=H;i++){
        cin >> input;
        for(int j=0;j<W;j++){
            if(input[j] == '.'){
                board[i][j+1] = 10;
                q.push({i, j+1});
            }
            else    board[i][j+1] = input[j] - '0';
        }
    }

    pair<int, int> cur;
    int result = -1, qsz, ci, cj, ni, nj;
    while(!q.empty()) {
        result++;
        qsz = q.size();
        for (int sz = 0; sz < qsz; sz++) {
            cur = q.front();
            q.pop();

            ci = cur.first;
            cj = cur.second;
            for (int d = 0; d < 8; d++) {
                ni = ci + di[d];
                nj = cj + dj[d];

                if (ni < 1 || nj < 1 || ni > H || nj > W || cnt[ni][nj] >= board[ni][nj])
                    continue;

                cnt[ni][nj]++;
                if (cnt[ni][nj] >= board[ni][nj]) {
                    q.push({ni, nj});
                }

            }
        }
    }

    cout << result;
    return 0;
}
