def solve(N, d, l):
    if N==4:
        board2=copy.deepcopy(board)
        for i in l:
            move(board2, i)
        val=0
        for i in board2:
            val=max(board2, val)
        ans=max(ans, val)
        return
    solve(N+1, l+[1])
    solve(N+1, l+[2])
    solve(N+1, l+[3])
    solve(N+1, l+[4])

solve(0, [1])
solve(0, [2])
solve(0, [3])
solve(0, [4])