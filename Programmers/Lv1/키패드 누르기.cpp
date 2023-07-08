#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

#define ASTERISK 10
#define HASH 11
#define ROW 4
#define COL 3

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int pad[4][3] = {{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9},
                 {ASTERISK, 0, HASH}};

unordered_map<int, pair<int, int>> position_of;

queue<pair<int, int>> q;
bool is_visited[ROW][COL];

char get_hand(int number, int left, int right, string hand) {
    q = {};
    for(int r=0;r<ROW;r++)
        for(int c=0;c<COL;c++)
            is_visited[r][c] = false;
    pair<int, int> left_position = position_of[left];
    pair<int, int> right_position = position_of[right];
    
    pair<int, int> current;
    int ci, cj, ni, nj, qsz;
    bool is_left = false, is_right = false;
    
    q.push(position_of[number]);
    
    while(!q.empty() && !is_left && !is_right){
        qsz = q.size();
    
        while(qsz--){
            current = q.front();
            q.pop();
            
            ci = current.first;
            cj = current.second;
            if(current == left_position) is_left = true;
            else if(current == right_position)  is_right = true;
            
            for(int d=0;d<4;d++){
                ni = ci + di[d];
                nj = cj + dj[d];
                if(ni < 0 || ni >= ROW || nj < 0 || nj >= COL || is_visited[ni][nj])  continue;
                is_visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
    
    if(is_left && is_right) {
        if(hand == "left")  return 'L';
        else    return 'R';
    }
    else if(is_left)    return 'L';
    else    return 'R';
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = ASTERISK, right = HASH;
    
    position_of[0] = {3, 1};
    position_of[1] = {0, 0};
    position_of[2] = {0, 1};
    position_of[3] = {0, 2};
    position_of[4] = {1, 0};
    position_of[5] = {1, 1};
    position_of[6] = {1, 2};
    position_of[7] = {2, 0};
    position_of[8] = {2, 1};
    position_of[9] = {2, 2};
    position_of[10] = {3, 0};
    position_of[11] = {3, 2};
    
    for(int number : numbers) {
        if(number == 1 || number == 4 || number == 7)   {
            answer = answer + 'L';
            left = number;
        }
        else if(number == 3 || number == 6 || number == 9) {
            answer = answer + 'R';  
            right = number;
        } 
        else {
            char hand_c = get_hand(number, left, right, hand);
            if(hand_c == 'L')   left = number;
            else    right = number;
            answer = answer + hand_c;
            
        }
    }
    return answer;
}