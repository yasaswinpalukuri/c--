'''
Depth First Search
    -> It is a graph traversal algorithm, allows cycling unlike graphs
    -> It is a recursive algorithm
    -> It uses the concept of backtracking
    -> It uses stack data structure
    -> It uses a boolean array to mark visited nodes
    -> It is used to solve problems like:
        => Finding connected components in a graph
        => Solving puzzles like mazes
        => Finding the path between two nodes in a graph
        => Finding the cycle in a graph
    
    -> Time Complexity: O(V+E), V: Number of vertices, E: Number of edges
    -> Space Complexity: O(V) -> O(V + E) if stack space is considered

'''

def dfs(graph, start_node):
    visited = set()  # Set to keep track of visited nodes
    stack = [start_node]  # Stack to store nodes to visit

    while stack:
        node = stack.pop()  # Get the next node to visit

        if node not in visited:
            visited.add(node)  # Mark the node as visited
            print(node)  # Process the node (you can modify this part)

            # Add the unvisited neighbors of the current node to the stack
            for neighbor in graph[node]:
                if neighbor not in visited:
                    stack.append(neighbor)

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

dfs(graph, 'A')