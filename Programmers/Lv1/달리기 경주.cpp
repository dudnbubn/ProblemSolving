#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<string, int> ranking_of;
map<int, string> name_of;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    int ranking;
    string name;
    string passed_name;
    for (int i = 0; i < players.size(); i++) {
        name = players[i];
        ranking_of[name] = i + 1;
        name_of[i + 1] = name;
    }

    for (string calling : callings) {
        ranking = ranking_of[calling];
        passed_name = name_of[ranking - 1];

        ranking_of[calling]--;
        ranking_of[passed_name]++;
        name_of[ranking - 1] = calling;
        name_of[ranking] = passed_name;
    }

    for (pair<int, string> name : name_of) {
        answer.push_back(name.second);
    }
    return answer;
}