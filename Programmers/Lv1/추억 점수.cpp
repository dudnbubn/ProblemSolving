#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> yearning_point;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int N = name.size();
    for(int n=0;n<N;n++) {
        yearning_point[name[n]] = yearning[n];
    }
    
    int sum;
    for(vector<string> names : photo) {
        sum = 0;
        for(string name : names) {
            if(yearning_point.find(name) != yearning_point.end()) {
                sum += yearning_point[name];
            }
        }
        answer.push_back(sum);
    }
    return answer;
}