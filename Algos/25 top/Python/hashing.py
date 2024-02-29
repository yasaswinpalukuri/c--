'''
Hashing
    -> it is process of generating fixed size output
    -> Hashing is the process of converting a given key into another value. 
    -> A hash function is used to generate the new value according to a mathematical algorithm.
    -> It has 3 basic components:
        => key -> is the index of the hashed values
        => Hash Function -> is the function that maps the key to the index of the array
        => Hash Table -> is the array that stores the values

    -> Hash functions:
        => Division Method
        => Multiplication Method
        => Universal Hashing
        => Mid Square Method

    
    -> Time Complexity:
        => O(1), Average
        => O(n), Worst case
        => O(1), Best case
    
    -> Space Complexity: O(n)

    -> Collision:
        => It is a situation when two keys hash to the same index in the hash table
        => There are two ways to handle collisions:
            -> Open Addressing => Closed hashing --> Linear Probing, Quadratic Probing, Double Hashing
            -> Separate Chaining => Open hashing --> Linked List, Binary Search Tree
    
    -> Advantages:
        => It is a fast and efficient way to access data
        => It is easy to implement
        => Key-value support
        => Scalability
        => Security and Encryption

    -> Disadvantages:
        => Collisions
        => Performance depends on the hash function
        => Not suitable for small data
        => Not suitable for complex data

    -> Applications:
        => Database indexing
        => Caching
        => Password security
        => Cryptography
        => Load balancing
'''

def hashFunction(key, size):
    return key % size

class HashTable:
    def __init__(self):
        self.MAX = 10
        self.arr = [None for i in range(self.MAX)]
    
    def get_hash(self, key):
        return key % self.MAX
    
    def __setitem__(self, key, value):
        h = self.get_hash(key)
        self.arr[h] = value
    
    def __getitem__(self, key):
        h = self.get_hash(key)
        return self.arr[h]
    
    def __delitem__(self, key):
        h = self.get_hash(key)
        self.arr[h] = None

t = HashTable()
t[23] = "apple"
t[25] = "mango"
t[27] = "banana"
print(t.arr)
print(t[25])
del t[25]
print(t.arr)
