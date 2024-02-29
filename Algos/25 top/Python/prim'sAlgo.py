'''
Prim's alogrithm
    -> Greedy algorithm
    -> Uses the minimum spanning tree for a connected weighted graph
    -> Time Complexity: O(V^2)
    -> Space Complexity: O(V)
    -> V: number of vertices
'''
def minKey(key, mstSet, V):
    min = float('inf')
    min_index = 0
    for v in range(V):
        if key[v] < min and mstSet[v] == False:
            min = key[v]
            min_index = v
    return min_index

def primMST(graph, V):
    key = [float('inf')] * V
    parent = [None] * V
    key[0] = 0
    mstSet = [False] * V
    parent[0] = -1
    for cout in range(V):
        u = minKey(key, mstSet, V)
        mstSet[u] = True
        for v in range(V):
            if graph[u][v] > 0 and mstSet[v] == False and key[v] > graph[u][v]:
                key[v] = graph[u][v]
                parent[v] = u
    return parent

graph = [[0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0]]
V = 5
parent = primMST(graph, V)
print("Edge \tWeight")
for i in range(1, V):
    print(parent[i], "-", i, "\t", graph[i][parent[i]])
