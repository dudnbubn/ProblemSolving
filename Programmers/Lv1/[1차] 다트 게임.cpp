#include <string>

using namespace std;

int index;
int scores[3];

int get_score(int score, char bonus) {
    int result = score;
    switch(bonus) {
        case 'D':   result = score * score;             break;
        case 'T':   result = score * score * score;  break;
    }
    return result;
}

int solution(string dartResult) {
    int answer = 0;
    int N = dartResult.size();
    
    int score;
    char bonus;
    char option;
    for(int n=0;n<N;n++) {
        if(dartResult[n+1] == '0') {
            score = 10;
            n++;
        }
        else {
            score = dartResult[n] - '0';
        }
        
        bonus = dartResult[n+1];
        
        scores[index] = get_score(score, bonus);
        
        if(n+2 < N && (dartResult[n+2] == '*' || dartResult[n+2] == '#')) {
            option = dartResult[n+2];
            if(option == '*') {
                scores[index] *= 2;
                if(index > 0)  
                    scores[index-1] *= 2;
            }
            else {
                scores[index] *= -1;
            }
            n++;
        }
        n++;
        index++;
    }
    
    for(int i=0;i<3;i++){
        answer += scores[i];
    }
    
    return answer;
}