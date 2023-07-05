#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<pair<int, int>> stk;

int solution(vector<int> ingredient) {
    int answer = 0;
    for(int ing : ingredient) {
        if(ing == 1){
            if(!stk.empty() && stk.top().first == 3 && stk.top().first == stk.top().second) {
                answer++;
                for(int i=0;i<3;i++)    stk.pop();
            }
            else{
                stk.push({ing, ing});
            }
        }
        else {
            if(!stk.empty() && stk.top().first == stk.top().second && stk.top().first == ing - 1) {
                stk.push({ing, ing});
            }
            else{
                stk.push({ing, 0});
            }
        }
    }
    
    return answer;
}