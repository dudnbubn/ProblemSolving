#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M, fuel;
int board[21][21];
bool visited[21][21];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
pair<int, int> passenger[401];
pair<int, int> destination[401];

queue<pair<int, int>> q;
vector<pair<int, int>> save;

int getPassenger(pair<int, int> taxi){
    q={};
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            visited[i][j] = false;

    int ci = taxi.first, cj = taxi.second;
    visited[ci][cj] = true;
    q.push({ci, cj});
    pair<int, int> cur;
    int ni, nj, qsz, level = -1;
    while(!q.empty()){
        save={};
        level++;
        if(level > fuel)  return -1;
        qsz=q.size();
        for(int sz=0;sz<qsz;sz++){
            cur = q.front();
            q.pop();

            ci = cur.first;
            cj = cur.second;
            if(1 <= board[ci][cj] && board[ci][cj] <= M){
                fuel -= level;

                int result = board[ci][cj];
                board[ci][cj] = 0;
                return result;
            }
            for(int d=0;d<4;d++){
                ni = ci + di[d];
                nj = cj + dj[d];
                if(ni<1||nj<1||ni>N||nj>N||board[ni][nj]==-1)
                    continue;

                if(board[ni][nj] >= 0 && !visited[ni][nj]){
                    visited[ni][nj] = true;
                    save.push_back({ni, nj});
                }
            }
        }
        sort(save.begin(), save.end());
        for(pair<int, int> p : save)
            q.push(p);
    }
    return -1;
}

int goToDestination(pair<int, int> taxi, int dest){
    q={};
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            visited[i][j] = false;

    int ci = taxi.first, cj = taxi.second;
    int ei = destination[dest].first, ej = destination[dest].second;
    visited[ci][cj] = true;
    q.push({ci, cj});
    pair<int, int> cur;
    int ni, nj, qsz, level = -1;
    while(!q.empty()){
        level++;
        if(level > fuel)    return -1;
        qsz=q.size();
        for(int sz=0;sz<qsz;sz++){
            cur = q.front();
            q.pop();

            ci = cur.first;
            cj = cur.second;
            if(ci == ei && cj == ej){
                fuel += level;
                return dest;
            }
            for(int d=0;d<4;d++){
                ni = ci + di[d];
                nj = cj + dj[d];

                if(ni<1||nj<1||ni>N||nj>N||board[ni][nj]==-1)
                    continue;

                if(board[ni][nj] >= 0 && !visited[ni][nj]){
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> fuel;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> board[i][j];
            if(board[i][j]) board[i][j]=-1;
        }
    }

    pair<int, int> taxi;
    cin >> taxi.first >> taxi.second;

    for(int i=1;i<=M;i++){
        int si, sj, ei, ej;
        cin >> si >> sj >> ei >> ej;
        board[si][sj] = i;
        passenger[i] = {si, sj};
        destination[i] = {ei, ej};
    }

    int clear = 0;
    while(true){
        int pass = getPassenger(taxi);
        if(pass < 0)    break;
        taxi = passenger[pass];
        int dest = goToDestination(taxi, pass);
        if(dest < 0)    break;
        taxi = destination[dest];
        clear++;
    }

    cout << (fuel < 0 || clear < M ? -1 : fuel);
    return 0;
}