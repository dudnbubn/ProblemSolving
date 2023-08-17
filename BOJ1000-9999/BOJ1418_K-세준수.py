import math

def is_prime(number):
    for i in range(2, int(math.ceil(math.sqrt(number + 1)))):
        if number % i == 0:
            return False
    return True

N = int(input())
K = int(input())

dp = [False] * 100_001

if N <= K:
    print(N)
else:
    result = -1
    for k in range(K+1):
        dp[k] = True
        result += 1

    for n in range(K+1, N+1):
        if is_prime(n) == False:
            for i in range(2, int(math.ceil(math.sqrt(n + 1)))):
                if n % i == 0:
                    dp[n] = dp[i] and dp[n//i]
                    if dp[n]:
                        result += 1
                    break

    print(result)


