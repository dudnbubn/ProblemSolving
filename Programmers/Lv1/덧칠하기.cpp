#include <string>
#include <vector>

using namespace std;

int end_index;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for(int sect : section) {
        if(sect > end_index) {
            answer++;
            end_index = sect + m - 1;
        }
    }
    return answer;
}