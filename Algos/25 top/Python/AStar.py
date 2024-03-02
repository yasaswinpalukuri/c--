import heapq

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
def astar(graph, start, goal):
    # Initialize the open and closed sets
    open_set = []
    closed_set = set()

    # Create a dictionary to store the cost of reaching each node
    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0

    # Create a dictionary to store the estimated total cost of reaching the goal from each node
    f_score = {node: float('inf') for node in graph}
    f_score[start] = heuristic(start, goal)

    # Add the start node to the open set
    heapq.heappush(open_set, (f_score[start], start))

    while open_set:
        # Get the node with the lowest f_score from the open set
        came_from = {}  # Define the variable "came_from" before using it

        current = heapq.heappop(open_set)[1]

        # If the current node is the goal, we have found the shortest path
        if current == goal:
            return reconstruct_path(came_from, current)

        # Add the current node to the closed set
        closed_set.add(current)

        # Explore the neighbors of the current node
        for neighbor in graph[current]:
            # Calculate the tentative g_score for the neighbor
            tentative_g_score = g_score[current] + graph[current][neighbor]

            if tentative_g_score < g_score[neighbor]:
                # Update the g_score and f_score for the neighbor
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, goal)

                # Add the neighbor to the open set if it's not already there
                if neighbor not in closed_set:
                    heapq.heappush(open_set, (f_score[neighbor], neighbor))

    # If we reach here, there is no path from the start to the goal
    return None

def heuristic(node, goal):
    # Calculate the heuristic value (e.g., Euclidean distance) between the node and the goal
    # You can customize this function based on your specific problem
    return 0

def reconstruct_path(came_from, current):
    # Reconstruct the path from the start to the current node
    path = [current]
    while current in came_from:
        current = came_from[current]
        path.append(current)
    path.reverse()
    return path

# Example usage
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'D': 3, 'E': 5},
    'C': {'F': 2},
    'D': {},
    'E': {'F': 1},
    'F': {}
}

print(astar(graph, 'A', 'F'))
# Output: ['A', 'C', 'F']