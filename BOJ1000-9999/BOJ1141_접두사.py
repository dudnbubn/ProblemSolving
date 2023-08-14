N = int(input())

words = []
for i in range(N):
    words.append(input())

words.sort()

result = N
for i in range(N-1):
    if words[i+1].startswith(words[i]):
        result -= 1

print(result)
