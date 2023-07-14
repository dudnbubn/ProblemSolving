#include <string>
#include <vector>

using namespace std;

int counts[10];
int x_count[10];

string solution(string X, string Y) {
    string answer = "";
    int number;
    
    for(char x : X) {
        number = x-'0';
        x_count[number]++;
    }
    
    for(char y : Y) {
        number = y-'0';
        if(x_count[number]) {
            x_count[number]--;
            counts[number]++;
        }
    }
    
    for(int i=9;i>=0;i--) {
        for(int j=0;j<counts[i];j++)
            answer.push_back(i+'0');
    }
    if(answer == "")    answer = "-1";
    else if(answer[0] =='0') answer = "0";
    
    return answer;
}