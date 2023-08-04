import math

dp = [0] * 100_001

def is_prime(number):
    if number <= 1:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True

for i in range(2, 100_001):
    if is_prime(i):
        dp[i] = 1
    else:
        if i % 2 == 0:
            dp[i] = dp[2] + dp[int(i/2)]
        else:
            for j in range(3,i):
                if i % j == 0:
                    dp[i] = dp[j] + dp[int(i/j)]
                    break

A, B = input().split()
A = int(A)
B = int(B)
result = 0
for i in range(A, B+1):
    if is_prime(dp[i]):
        result+=1

print(result)