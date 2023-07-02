#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = 50, luy = 50, rdx = 0, rdy = 0;
    int N = wallpaper.size();
    int M = wallpaper[0].size();
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (wallpaper[n][m] == '#') {
                lux = lux < n ? lux : n;
                luy = luy < m ? luy : m;
                rdx = rdx > n + 1 ? rdx : n + 1;
                rdy = rdy > m + 1 ? rdy : m + 1;
            }
        }
    }
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    return answer;
}