#include <string>
#include <vector>

using namespace std;

int positions[26];

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int a=0;a<26;a++)    positions[a] = -1;
    
    int N = s.size();
    char alphabet;
    for(int n=0;n<N;n++) {
        alphabet = s[n];
        if(positions[alphabet-'a'] == -1)  
            answer.push_back(-1);
        else 
            answer.push_back(n - positions[alphabet-'a']);
        
        positions[alphabet-'a'] = n;
    }
    
    return answer;
}