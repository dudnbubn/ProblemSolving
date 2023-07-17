#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int N = food.size();
    for(int n=1;n<N;n++) {
        for(int m=0;m<food[n]/2;m++) {
            answer.push_back('0'+n);
        }
    }
    answer.push_back('0');
    for(int n=N-1;n>=1;n--) {
        for(int m=0;m<food[n]/2;m++) {
            answer.push_back('0'+n);
        }
    }
    return answer;
}