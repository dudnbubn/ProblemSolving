#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int get_dir(char dir){
    switch(dir){
        case 'N':   return 0;
        case 'E':   return 1;
        case 'S':   return 2;
        case 'W':   return 3;
    }
}

pair<int, int> get_next_position(vector<string> &park, int ci, int cj, int dir, int dist){
    for(int d=0;d<dist;d++){
        ci += di[dir];
        cj += dj[dir];
        
        if(ci < 0 || ci >= N || cj < 0 || cj >= M || park[ci][cj] == 'X')
            return {-1, -1};
    }
    return {ci, cj};
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    N = park.size();
    M = park[0].size();
    int ci, cj;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(park[i][j] == 'S'){
                ci = i;
                cj = j;
            }
        }
    }
    
    int dir, dist;
    pair<int, int> next_position;
    for(string route : routes) {
        dir = get_dir(route[0]);
        dist = route[2] - '0';
        next_position = get_next_position(park, ci, cj, dir, dist);
        
        if(next_position.first == -1)   continue;
        ci = next_position.first;
        cj = next_position.second;
    }
    
    answer.push_back(ci);
    answer.push_back(cj);
    return answer;
}
