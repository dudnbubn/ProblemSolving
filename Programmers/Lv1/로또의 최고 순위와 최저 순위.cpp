#include <string>
#include <vector>

using namespace std;

int get_ranking(int equal_count) {
    return equal_count == 0 ? 6 : 7 - equal_count;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int equal_count = 0;
    int zero_count = 0;
    for(int lotto : lottos) {
        if(lotto == 0)  zero_count++;
        else {
            for(int win_num : win_nums) {
                if(lotto == win_num) {
                    equal_count++;
                    break;
                }
            }
        }
    }
    answer.push_back(get_ranking(equal_count + zero_count));
    answer.push_back(get_ranking(equal_count));
    return answer;
}