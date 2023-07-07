#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    char alphabet;
    for(int i=0;i<s.size();i++){
        alphabet = s[i];
        for(int j=0;j<index;){
            if(alphabet == 'z'){
                alphabet = 'a';
            }
            else{
                alphabet = alphabet+1;
            }
            if(skip.find(alphabet) != -1)   continue;
            j++;
        }
        answer = answer + alphabet;
    }
    return answer;
}