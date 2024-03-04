'''
Rabin Karp Algorithm
    -> A string searching algo that uses hashing to find patterns in string
    -> It uses a rolling hash to quickly filter out positions of the string that cannot match the pattern
    **-> It is a probabilistic algorithm that can have false positives
    -> It prints all the occurence of the pattern in the string assuming len(patt) <= len(text)
    **-> It uses a prime number to hash the pattern and the text
    -> Time Complexity:
        => Best case: O(n+m)
        => Worst case: O(n*m)
    -> Space Complexity: O(1)

    -> Limitations:
        => Spurious Hit: Value of hash matches but the string is different.
        => Not prefered for large patterns as the hash vallues will be large and hard to process.
'''

def rabinKarp(text, patt):
    # Prime number to hash the pattern and the text
    prime = 101
    # Length of the pattern and the text
    n, m = len(text), len(patt)
    # Hash value of the pattern and the text
    hashP, hashT = 0, 0
    # Value of the prime raised to the power of m-1
    power = 1
    # List to store the occurence of the pattern in the text
    occ = []
    # Calculate the hash value of the pattern and the first window of the text
    for i in range(m):
        hashP = (hashP*prime + ord(patt[i]))%prime
        hashT = (hashT*prime + ord(text[i]))%prime
        if i != 0:
            power = (power*prime)%prime
    # Slide the window and check for the occurence of the pattern
    for i in range(n-m+1):
        # Check if the hash value of the pattern and the text matches
        if hashP == hashT:
            # Check if the pattern matches the text
            if patt == text[i:i+m]:
                occ.append(i)
        # Slide the window
        if i < n-m:
            hashT = (hashT - ord(text[i])*power)%prime
            hashT = (hashT + prime)%prime
            hashT = (hashT*prime + ord(text[i+m]))%prime
    return occ

# Testing the algorithm
text = "AABAACAADAABAABA"
patt = "AABA"
print("Text is:",text,"\nPattern is:",patt)
occurences = rabinKarp(text, patt)
print("There are a total of",len(occurences),"occurences of the pattern in the text at the following positions:",occurences)
