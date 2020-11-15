def solution(money):
    n=len(money)
    dp=[money[0], money[0]]
    for i in range(2, n-1):
        dp.append(max(dp[i-2]+money[i], dp[-1]))
    dp2=[0, money[1]]
    for i in range(2, n):
        dp2.append(max(dp[i-2]+money[i], dp2[-1]))

    return max(dp[-1], dp2[-1])

print(solution([1,2,3,1]))