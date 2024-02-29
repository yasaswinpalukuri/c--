'''
Breath First Search
    -> Starts with root node and explores all nodes at a level before moving to the next level
    -> It uses queue data structure
    -> It uses a boolean array to mark visited nodes
    -> It is used to solve problems like:
        => Finding the shortest path in an unweighted graph
        => Finding the connected components in a graph
        => Solving puzzles like mazes
        => Finding the path between two nodes in a graph
        => Finding the cycle in a graph
    
    -> Time Complexity: O(V+E), V: Number of vertices, E: Number of edges
    -> Space Complexity: O(V)

'''

from collections import deque

def bfs(graph, start_node):
    visited = set()  # Set to keep track of visited nodes
    queue = deque([start_node])  # Queue to store nodes to visit

    while queue:
        node = queue.popleft()  # Get the next node to visit

        if node not in visited:
            visited.add(node)  # Mark the node as visited
            print(node)  # Process the node (you can modify this part)

            # Add the unvisited neighbors of the current node to the queue
            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

bfs(graph, 'A')
# Output: A B C D E F