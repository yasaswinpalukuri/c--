'''
A* algorithm
    -> It is used to find the shortest path between an initial and a final point(i.e, path-finding and graph traversal)
    -> Unlike other traversal technique, A* is intelligent and has a working brain
    -> Many games and web-based maps usse A* alogrithm for route opitmization
    -> It uses a heuristic to estimate the total cost of the path through the current node as:
        => f(n) = g(n) + h(n)
            -> f(n) = Total cost of the node
            -> g(n) = Cost of the path from the start node to n
            -> h(n) = Cost of the path from n to the goal node
    -> It uses priority queue data structure
    -> It uses a boolean array to mark visited nodes
    -> It is used to solve problems like:
        => Finding the shortest path in a weighted graph
        => Finding the path between two nodes in a graph
        => Solving puzzles like mazes
        => Finding the path in a maze
        => Finding the path in a grid
        => Finding the path in a 2D matrix
        => Finding the path in a 3D matrix
        => Finding the path in a 4D matrix
        => Finding the path in a nD matrix
    
    -> Time Complexity: O(E + VlogV), E: Number of edges, V: Number of vertices
    -> Space Complexity: O(V)

'''

from queue import PriorityQueue

def a_star(graph, start_node, end_node):
    visited = set()  # Set to keep track of visited nodes
    queue = PriorityQueue()  # Priority queue to store nodes to visit
    queue.put((0, start_node))  # Add the start node to the queue
    parent = {start_node: None}  # Dictionary to store the parent of each node
    g = {start_node: 0}  # Dictionary to store the cost of the path from the start node to each node

    while not queue.empty():
        cost, node = queue.get()  # Get the next node to visit

        if node == end_node:
            path = []
            while node is not None:
                path.append(node)
                node = parent[node]
            return path[::-1]

        if node not in visited:
            visited.add(node)  # Mark the node as visited

            # Add the unvisited neighbors of the current node to the queue
            for neighbor, weight in graph[node]:
                if neighbor not in visited:
                    if neighbor not in g or g[node] + weight < g[neighbor]:
                        g[neighbor] = g[node] + weight
                        f = g[neighbor] + heuristic(neighbor, end_node)
                        queue.put((f, neighbor))
                        parent[neighbor] = node

    return None

def heuristic(node, end_node):
    # This is a sample heuristic function. You can modify this function to get better results
    return 0

# Example usage
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 2), ('E', 5)],
    'C': [('F', 3)],
    'D': [],
    'E': [('F', 1)],
    'F': []
}

print(a_star(graph, 'A', 'F'))
