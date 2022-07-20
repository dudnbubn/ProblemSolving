#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<pair<char, int>> stk;

int main() {
    string ppap;
    cin >> ppap;

    for (int i = 0; i < ppap.size(); i++) {
        if (ppap[i] == 'P') {
            if (stk.empty()) {
                stk.push({ 'P', 1 });
            }
            else {
                if (stk.top().first == 'P')
                    stk.push({ 'P', stk.top().second + 1 });
                else {
                    int save = stk.top().second;
                    for (int j = 0; j < 3; j++)
                        stk.pop();
                    stk.push({ 'P', save });
                }
            }
        }
        else {
            if (stk.empty() || stk.top().first == 'A') {
                cout << "NP";
                exit(0);
            }
            else {
                if (stk.top().second == 1) {
                    cout << "NP";
                    exit(0);
                }
                else {
                    stk.push({ 'A', stk.top().second - 1 });
                }
            }
        }
    }

    if (stk.size() == 1) cout << "PPAP";
    else  cout << "NP";

    return 0;
}
