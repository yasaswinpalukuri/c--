'''
Topological Sorting
    -> It is mainly used for scheduling jobs from the given dependencies among jobs
    -> V is the number of vertices and E is the number of edges
    -> Time Complexity: O(V+E)
    -> Space Complexity: O(V)
    -> V is the number of vertices and E is the number of edges
    -> It is not possible if the graph is not a DAG (Directed Acyclic Graph)
    -> Uses temporary stack to store the vertices
'''

def topologicalSort(graph):
    visited = [False] * len(graph)
    stack = []
    for i in range(len(graph)):
        if not visited[i]:
            topologicalSortUtil(graph, i, visited, stack)
    return stack[::-1]

def topologicalSortUtil(graph, v, visited, stack):
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            topologicalSortUtil(graph, i, visited, stack)
    stack.append(v)

graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: [4],
    4: []
}
print(topologicalSort(graph))  # [0, 2, 1, 3, 4]