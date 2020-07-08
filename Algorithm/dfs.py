'''
DFS
깊이 우선 탐색
'''

graph={
    1:[3],
    2:[3],
    3:[1,2,4],
    4:[3,5,7],
    5:[4,6],
    6:[5],
    7:[4,8,9],
    8:[7],
    9:[7]
}

def dfs(graph, node):
    visited=[]
    stack=[node]

    while stack:
        n=stack.pop()
        if n not in visited:
            visited.append(n)
            stack.extend(graph[n])
    return visited

print(dfs(graph, 1))