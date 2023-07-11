#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> basket;
stack<int> colums[30];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i=board.size()-1;i>=0;i--) {
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == 0)    continue;
            colums[j].push(board[i][j]);
        }
    }
    
    int doll;
    for(int move : moves) {
        move--;
        if(colums[move].empty())    continue;
        
        doll = colums[move].top();
        colums[move].pop();
        
        if(!basket.empty() && basket.top() == doll) {
            answer += 2;
            basket.pop();
        }
        else{
            basket.push(doll);
        }
    }
    
    return answer;
}