#include <string>
#include <vector>

using namespace std;

#define MAX_N 1'000'000

bool is_prime[MAX_N+1];

void eratos(int N) {
    for(int n=2;n<=N;n++)
        is_prime[n] = true;
    
    for(int n=2;n*n<=N;n++) {
        if(is_prime[n]) {
            for(int m=n*n;m<=N;m+=n)
                is_prime[m] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    eratos(n);
    for(int i=2;i<=n;i++) {
        if(is_prime[i])
            answer++;
    }
    return answer;
}