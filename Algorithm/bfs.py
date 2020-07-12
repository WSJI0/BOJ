'''
BFS
너비 우선 탐색
'''

graph={
    0:{1,2},
    1:{0,3,5},
    2:{0,6,8},
    3:{1,4},
    4:{3,5},
    5:{1,4},
    6:{2,7,8},
    7:{6},
    8:{2,6}
}

def bfs(graph, node):
    visited=[]
    queue=[node]
    
    while queue:
        n=queue.pop(0)
        if n not in visited:
            visited.append(n)
            queue.extend(graph[n])
    return visited
                

print(bfs(graph,0))