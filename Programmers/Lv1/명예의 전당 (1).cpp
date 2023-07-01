#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    for (int sc : score) {
        pq.push(sc);
        while (pq.size() > k)    pq.pop();
        answer.push_back(pq.top());
    }
    return answer;
}