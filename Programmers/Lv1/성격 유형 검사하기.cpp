#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> index_of;
unordered_map<int, char> char_of;
int scores[8];

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    index_of['R'] = 0;  char_of[0] = 'R';
    index_of['T'] = 1;  char_of[1] = 'T';
    index_of['C'] = 2;  char_of[2] = 'C';
    index_of['F'] = 3;  char_of[3] = 'F';
    index_of['J'] = 4;  char_of[4] = 'J';
    index_of['M'] = 5;  char_of[5] = 'M';
    index_of['A'] = 6;  char_of[6] = 'A';
    index_of['N'] = 7;  char_of[7] = 'N';
    
    int N = survey.size();
    int index;
    for(int i=0;i<N;i++){
        if(choices[i] < 4){
            index = index_of[survey[i][0]];
            scores[index] += 4 - choices[i];
        }
        else{
            index = index_of[survey[i][1]];
            scores[index] += choices[i] - 4;
        }
    }
    
    for(int i=0;i<8;i+=2){
        if(scores[i] >= scores[i+1])    answer = answer + char_of[i];
        else    answer = answer + char_of[i+1];
    }
    
    return answer;
}