#include <string>
#include <vector>

using namespace std;

bool can_babbling(string babbling) {
    string prev;
    string word;
    for(int i=0;i<babbling.size();i++) {
        if(babbling[i] == 'y' || babbling[i] == 'm') {
            word = babbling.substr(i, 2);
            if(word == prev)    return false;
            
            if(word == "ye" || word == "ma") {
                i+=1;
            }
            else{
                return false;
            }
        }
        else if(babbling[i] == 'a' || babbling[i] == 'w') {
            word = babbling.substr(i, 3);
            if(word == prev)    return false;
            
            if(word == "aya" || word == "woo") {
                i+=2;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
        prev = word;
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for(string word : babbling) {
        if(can_babbling(word))  answer++;
    }
    return answer;
}