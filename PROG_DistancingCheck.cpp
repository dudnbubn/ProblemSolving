//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<vector<string>> places) {
//    vector<int> answer;
//    for (int i = 0; i < 5; i++) {
//        bool flag = false;
//        vector<pair<int, int>> cand;
//        for (int j = 0; j < 5; j++) {
//            for (int k = 0; k < 5; k++) {
//                if (places[i][j][k] == 'P')
//                    cand.push_back(make_pair(j, k));
//            }
//        }
//        for (int j = 0; j < cand.size() - 1; j++) {
//            for (int k = j + 1; k < cand.size(); k++) {
//                int dis_x = abs(cand[j].first - cand[k].first);
//                int dis_y = abs(cand[j].second - cand[k].second);
//                if (dis_x + dis_y == 1)
//                    flag = true;
//                else if (dis_x + dis_y > 2)
//                    continue;
//                else {
//                    int x1 = cand[j].first, y1 = cand[j].second;
//                    int x2 = cand[k].first, y2 = cand[k].second;
//                    if (x1 == x2) {
//                        if (places[i][x1][(y1 + y2) / 2] != 'X')
//                            flag = true;
//                    }
//                    else if (y1 == y2) {
//                        if (places[i][(x1 + x2) / 2][y1] != 'X')
//                            flag = true;
//                    }
//                    else {
//                        if (places[i][x2][y1] != 'X' || places[i][x1][y2] != 'X')
//                            flag = true;
//                    }
//                }
//                if (flag) {
//                    j = cand.size();
//                    break;
//                }
//            }
//        }
//        if (flag)
//            answer.push_back(0);
//        else
//            answer.push_back(1);
//    }
//    return answer;
//}