#include <string>
#include <vector>

using namespace std;

int students[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=1;i<=n;i++)   students[i] = 1;
    for(int number : lost) {
        students[number]--;
    }
    for(int number : reserve) {
        students[number]++;
    }
    
    for(int i=1;i<=n;i++) {
        if(students[i] == 0) {
            if(students[i-1] == 2) {
                students[i-1]--;
                students[i]++;
            }
            else if(students[i+1] == 2) {
                students[i+1]--;
                students[i]++;
            }
        }
    }
    
    for(int i=1;i<=n;i++) {
        if(students[i]) answer++;
    }
    return answer;
}