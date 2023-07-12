#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char first_char;
    int equal_count = 0;
    int non_equal_count = 0;
    for(int i=0;i<s.size();i++) {
        if(equal_count == 0) {
            first_char = s[i];
            equal_count = 1;
        }
        else{
            if(s[i] == first_char) {
                equal_count++;
            }
            else {
                non_equal_count++;
            }
        }
        
        if(equal_count == non_equal_count) {
            answer++;
            equal_count = non_equal_count = 0;
        }
    }
    
    if(equal_count) answer++;
    
    return answer;
}