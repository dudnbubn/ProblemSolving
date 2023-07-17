#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 500
typedef pair<pair<long long, long long>, int> plllli;

bool compare(plllli a, plllli b) {
    long long aa = a.first.first * b.first.second;
    long long bb = b.first.first * a.first.second;
    if(aa == bb)    return a.second < b.second;
    return aa > bb;
}

plllli arr[MAX_N+1];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    
    long long denom, numer;
    
    for(int n=1;n<=N;n++) {
        denom = stages.size() - (lower_bound(stages.begin(), stages.end(), n) - stages.begin());
        numer = upper_bound(stages.begin(), stages.end(), n) - lower_bound(stages.begin(), stages.end(), n);
        arr[n] = {{numer, denom}, n};
        cout << "arr[" << n << "] = " << arr[n].first.first << ", " << arr[n].first.second << ", " << arr[n].second << "\n";
    }
    
    sort(arr+1, arr+N+1, compare);
    for(int n=1;n<=N;n++) answer.push_back(arr[n].second);
    return answer;
}