#include <string>
#include <vector>

using namespace std;

int get_factor_count(int number){
    int result = 0;
    
    for(int i=1;i*i<=number;i++){
        if(number % i == 0){
            if(i == number / i) result++;
            else    result+=2;
        }
    }
    return result;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    int factor_count;
    for(int i=1;i<=number;i++){
        factor_count = get_factor_count(i);
        if(factor_count > limit)    answer += power;
        else    answer += factor_count;
    }
    return answer;
}