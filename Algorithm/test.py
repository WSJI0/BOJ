import sys

def dp(n, now_h):
    if N==n:
        return 0
    if now_h < list_h[n]:
        return n
    if now_h > list_h[n]:
        if not list_res[n] == 0:
            return dp(list_res[n], now_h)
        else:
            return (0 if list_h[n] < now_h else n)
    if not list_res[n] == -1:
        return list_res[n]
    list_res[n] = dp(n+1, now_h)
    return list_res[n]
    

N = int(sys.stdin.readline())
list_h = [int(sys.stdin.readline()) for _ in range(N)]
list_h.append(0)
list_res = [-1]*(N)
list_res.append(0)
for i in range(N-1, -1, -1):
    dp(i, list_h[i])
[print(list_res[i] + (1 if list_res[i] else 0)) for i in range(N)]