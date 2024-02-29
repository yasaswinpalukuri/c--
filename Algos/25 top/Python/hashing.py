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

# Function to display hashtable 
def display_hash(hashTable): 
	
	for i in range(len(hashTable)): 
		print(i, end = " ") 
		
		for j in hashTable[i]: 
			print("-->", end = " ") 
			print(j, end = " ") 
			
		print() 

# Creating Hashtable as 
# a nested list. 
HashTable = [[] for _ in range(10)] 

# Hashing Function to return 
# key for every value. 
def Hashing(keyvalue): 
	return keyvalue % len(HashTable) 


# Insert Function to add 
# values to the hash table 
def insert(Hashtable, keyvalue, value): 
	
	hash_key = Hashing(keyvalue) 
	Hashtable[hash_key].append(value) 

# Driver Code 
insert(HashTable, 10, 'Allahabad') 
insert(HashTable, 25, 'Mumbai') 
insert(HashTable, 20, 'Mathura') 
insert(HashTable, 9, 'Delhi') 
insert(HashTable, 21, 'Punjab') 
insert(HashTable, 21, 'Noida') 

display_hash (HashTable) 
