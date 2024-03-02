'''
Bresenham's Line Algorithm
    -> It is used to determine the points that lie in between two points on a 2D plane
    -> Time Complexity: O(n), where n is the number of pixels in the line
    -> Space Complexity: O(1)
    -> It is used in computer graphics to draw lines
    -> It is implemented using the "Principle of Rasterization"
'''

def bresenhamLineAlgorithm(x1, y1, x2, y2):
    points = []
    dx = x2 - x1
    dy = y2 - y1
    p = 2 * dy - dx
    twoDy = 2 * dy
    twoDyMinusDx = 2 * (dy - dx)
    x, y = x1, y1
    if x1 > x2:
        x = x2
        y = y2
        x2 = x1
    points.append((x, y))
    while x < x2:
        x += 1
        if p < 0:
            p += twoDy
        else:
            y += 1
            p += twoDyMinusDx
        points.append((x, y))
    return points

# Example usage
print(bresenhamLineAlgorithm(1, 1, 5, 3))
# Output: [(1, 1), (2, 1), (3, 2), (4, 2), (5, 3)]