#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

set<string> visited;
queue<pair<string, int>> q;

string swap(int a, int b, string s){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
    return s;
}

int main(){
    string sol = "123456780";
    vector<int> linked[9];
    int idx_arr[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    int ni, nj;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int d=0;d<4;d++){
                ni = i + di[d];
                nj = j + dj[d];

                if(ni < 0 || nj < 0 || ni >= 3 || nj >= 3)
                    continue;

                linked[idx_arr[i][j]].push_back(idx_arr[ni][nj]);
            }
        }
    }

    string cur = "";
    string input;
    for(int i=0;i<9;i++){
        cin >> input;
        cur.append(input);
    }
    int index=0;
    for(int i=0;i<10;i++)
        if(cur[i] == '0') index=i;

    int result = -1;

    q.push({cur, index});
    visited.insert(cur);
    pair<string, int> front;
    int qsz, level=-1;
    while(!q.empty()){
        level++;
        qsz = q.size();
        for(int sz=0;sz<qsz;sz++) {
            front = q.front();
            q.pop();

            cur = front.first;
            index = front.second;

            if (cur == sol) {
                result = level;
                break;
            }
            for (int link: linked[index]) {
                string next = swap(index, link, cur);
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, link});
                }
            }
        }
    }

    cout << result;

    return 0;
}