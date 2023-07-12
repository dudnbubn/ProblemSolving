#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int index1=0, index2=0;
    bool make_goal = true;
    for(string s : goal) {
        if(cards1[index1] == s) {
            index1++;
        }
        else if(cards2[index2] == s) {
            index2++;
        } 
        else {
            make_goal = false;
            break;
        }
    }
    
    answer = make_goal ? "Yes" : "No";
    return answer;
}