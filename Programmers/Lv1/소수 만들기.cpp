#include <vector>
#include <iostream>
using namespace std;

#define INF 3'000

bool is_prime[INF+1];

void eratos() {
    for(int i=2;i<=INF;i++)
        is_prime[i] = true;
    
    for(int i=2;i*i<=INF;i++) {
        if(is_prime[i]) {
            for(int j=i*i;j<=INF;j+=i)
                is_prime[j] = false;
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    eratos();
    
    int N = nums.size();
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            for(int k=j+1;k<N;k++) {
                if(is_prime[nums[i] + nums[j] + nums[k]])
                    answer++;
            }
        }
    }

    return answer;
}