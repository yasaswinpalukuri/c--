'''
Binary Tree
    -> Hierarchical Data Structure
    -> Each node as 0 or 1 or 2 children only
    -> The first node is called 'root'
    -> The last nodes are called 'leaves'
    -> Traversasl present in binary tree:
        -> Inorder: Left, Root, Right => Complexity: O(n)
        -> Preorder: Root, Left, Right => Complexity: O(n)
        -> Postorder: Left, Right, Root => Complexity: O(n)
        -> Levelorder: Level by level from left to right => Complexity: O(n)
        -> Reverse Levelorder: Level by level from right to left => Complexity: O(n)
        -> Spiral Levelorder: Level by level from left to right and right to left alternatively => Complexity: O(n)
    -> Applications:
        -> Expression Tree
        -> Huffman Coding
        -> Binary Search Tree, Binary Heap
        -> AVL Tree, Red-Black Tree
        -> B-Tree, B+ Tree
        -> Trie
        -> Segment & Fenwick Tree
    -> Functions
        -> Insertion
        -> Deletion
        -> Searching
        -> Traversal
        -> Height, Depth, Size
        -> view (Left, Right, Top, Diagonal) 
'''

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class binaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, root, key):
        if not root:
            return Node(key)
        if key < root.key:
            root.left = self._insert(root.left, key)
        elif key > root.key:
            root.right = self._insert(root.right, key)
        return root

    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _delete(self, root, key):
        if not root:
            return root
        if key < root.key:
            root.left = self._delete(root.left, key)
        elif key > root.key:
            root.right = self._delete(root.right, key)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            root.key = self._min_value_node(root.right)
            root.right = self._delete(root.right, root.key)
        return root

    def _min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current.key

    def search(self, key):
        return self._search(self.root, key)

    def _search(self, root, key):
        if not root or root.key == key:
            return root
        if key < root.key:
            return self._search(root.left, key)
        return self._search(root.right, key)

    def find_depth(self):
        return self._find_depth(self.root)

    def _find_depth(self, root):
        if not root:
            return 0
        left_depth = self._find_depth(root.left)
        right_depth = self._find_depth(root.right)
        return max(left_depth, right_depth) + 1

    def find_height(self):
        return self._find_height(self.root)

    def _find_height(self, root):
        if not root:
            return -1
        left_height = self._find_height(root.left)
        right_height = self._find_height(root.right)
        return max(left_height, right_height) + 1

    def level_order_traversal(self):
        if not self.root:
            return
        queue = [self.root]
        while queue:
            current = queue.pop(0)
            print(current.key, end=' ')
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)

    def inorder_traversal(self):
        self._inorder_traversal(self.root)

    def _inorder_traversal(self, root):
        if root:
            self._inorder_traversal(root.left)
            print(root.key, end=' ')
            self._inorder_traversal(root.right)

    def preorder_traversal(self):
        self._preorder_traversal(self.root)

    def _preorder_traversal(self, root):
        if root:
            print(root.key, end=' ')
            self._preorder_traversal(root.left)
            self._preorder_traversal(root.right)

    def postorder_traversal(self):
        self._postorder_traversal(self.root)

    def _postorder_traversal(self, root):
        if root:
            self._postorder_traversal(root.left)
            self._postorder_traversal(root.right)
            print(root.key, end=' ')

    def spiral_level_order_traversal(self):
        if not self.root:
            return
        stack1 = [self.root]
        stack2 = []
        while stack1 or stack2:
            while stack1:
                current = stack1.pop()
                print(current.key, end=' ')
                if current.right:
                    stack2.append(current.right)
                if current.left:
                    stack2.append(current.left)
            while stack2:
                current = stack2.pop()
                print(current.key, end=' ')
                if current.left:
                    stack1.append(current.left)
                if current.right:
                    stack1.append(current.right)
    def view(self):
        if not self.root:
            print("Tree is empty.")
        else:
            print("\nLeft View:")
            self._view_left(self.root, 1, [0])

            print("\nRight View:")
            self._view_right(self.root, 1, [0])

            print("\nTop View:")
            self._view_top(self.root, 0, {})

            print("\nDiagonal View:")
            self._view_diagonal(self.root, 0, {})

    def _view_left(self, root, level, max_level):
        if not root:
            return

        if level > max_level[0]:
            print(root.key, end=" ")
            max_level[0] = level

        self._view_left(root.left, level + 1, max_level)
        self._view_left(root.right, level + 1, max_level)

    def _view_right(self, root, level, max_level):
        if not root:
            return

        if level > max_level[0]:
            print(root.key, end=" ")
            max_level[0] = level

        self._view_right(root.right, level + 1, max_level)
        self._view_right(root.left, level + 1, max_level)

    def _view_top(self, root, horizontal_distance, vertical_distances):
        if not root:
            return

        if horizontal_distance not in vertical_distances:
            print(root.key, end=" ")
            vertical_distances[horizontal_distance] = root.key

        self._view_top(root.left, horizontal_distance - 1, vertical_distances)
        self._view_top(root.right, horizontal_distance + 1, vertical_distances)

    def _view_bottom(self, root, horizontal_distance, vertical_distances):
        if not root:
            return

        vertical_distances[horizontal_distance] = root.key

        self._view_bottom(root.right, horizontal_distance + 1, vertical_distances)
        self._view_bottom(root.left, horizontal_distance - 1, vertical_distances)

    def _view_diagonal(self, root, diagonal_distance, diagonal_distances):
        if not root:
            return

        if diagonal_distance not in diagonal_distances:
            print(root.key, end=" ")
            diagonal_distances[diagonal_distance] = root.key

        self._view_diagonal(root.left, diagonal_distance + 1, diagonal_distances)
        self._view_diagonal(root.right, diagonal_distance, diagonal_distances)

    def _reverse_level_order_traversal(self, root):
        if not root:
            return
        queue = [root]
        result = []
        while queue:
            current = queue.pop(0)
            result.insert(0, current.key)
            if current.right:
                queue.append(current.right)
            if current.left:
                queue.append(current.left)

        print(" ".join(map(str, result)))


# Main
def main():
    # Declaring the object for binaryTree class to access the methods
    binary_tree = binaryTree()

    # Temporarily inserting the elements into the binary tree, to check the functions working
    binary_tree.insert(50)
    binary_tree.insert(30)
    binary_tree.insert(20)
    binary_tree.insert(40)
    binary_tree.insert(70)
    '''
        50
       /  \
      30   70
     /  \
    20  40
    '''

    while True:
        print("\n\nBinary Tree Operations:")
        print("1. Insert")
        print("2. Delete")
        print("3. Search")
        print("4. Depth of the Tree")
        print("5. Height of the Tree")
        print("6. Level Order Traversal")
        print("7. Inorder Traversal")
        print("8. Preorder Traversal")
        print("9. Postorder Traversal")
        print("10. Spiral Level Order Traversal")
        print("11. View")
        print("12. Reverse Level Order Traversal")
        print("13. Exit")

        choice = int(input("Enter your choice (1-13): "))

        if choice == 1:
            key = int(input("Enter the key to insert: "))
            binary_tree.insert(key)
            print(f"{key} inserted into the tree.")
        elif choice == 2:
            key = int(input("Enter the key to delete: "))
            binary_tree.delete(key)
            print(f"{key} deleted from the tree.")
        elif choice == 3:
            key = int(input("Enter the key to search: "))
            if binary_tree.search(key):
                print(f"{key} found in the tree.")
            else:
                print(f"{key} not found in the tree.")
        elif choice == 4:
            print(f"Depth of the tree: {binary_tree.find_depth()}")
        elif choice == 5:
            print(f"Height of the tree: {binary_tree.find_height()}")
        elif choice == 6:
            print("Level Order Traversal:")
            binary_tree.level_order_traversal()
        elif choice == 7:
            print("Inorder Traversal:")
            binary_tree.inorder_traversal()
        elif choice == 8:
            print("Preorder Traversal:")
            binary_tree.preorder_traversal()
        elif choice == 9:
            print("Postorder Traversal:")
            binary_tree.postorder_traversal()
        elif choice == 10:
            print("Spiral Level Order Traversal:")
            binary_tree.spiral_level_order_traversal()
        elif choice == 11:
            binary_tree.view()
        elif choice == 12:
            print("Reverse Level Order Traversal:")
            binary_tree._reverse_level_order_traversal(binary_tree.root)
        elif choice == 13:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
