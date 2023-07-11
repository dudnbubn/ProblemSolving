#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, int> key_map;

int get_key_count(string target) {
    int result = 0;
    for(char c : target) {
        if(key_map.find(c) == key_map.end())    return -1;
        result += key_map[c];
    }
    return result;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(string key : keymap) {
        for(int i=0;i<key.size();i++){
            if(key_map.find(key[i]) == key_map.end())   key_map[key[i]] = i+1;
            else    key_map[key[i]] = min(key_map[key[i]], i+1);
        }
    }
    
    for(string target : targets) {
        answer.push_back(get_key_count(target));
    }
    
    return answer;
}