#String (str)
s = 'Hello World!' # "Hello World!" both are same
print(s) # Output: Hello World!
print(type(s)) # Output: <class 'str'>
print(s[0]) # Output: H
print(s[:5]) # Output: Hello [0-4]
print(s[6:]) # Output: World! [6-end]


#Integer (int)
i = 10
print(i) # Output: 10
print(type(i)) # Output: <class 'int'>

#Float (float)
f = 10.5
print(f) # Output: 10.5
print(type(f)) # Output: <class 'float'>

#Boolean (bool)
b = True
print(b) # Output: True
print(type(b)) # Output: <class 'bool'>

#List (list)
l = [1, 2, 3, 4]
print(l) # Output: [1, 2, 3, 4]
print(type(l)) # Output: <class 'list'>
print(l[0]) # Output: 1
print(l[:2]) # Output: [1, 2]
print(l[2:]) # Output: [3, 4]
# List can be modified


#Tuple (tuple)
t = (1, 2, 3, 4)
print(t) # Output: (1, 2, 3, 4)
print(type(t)) # Output: <class 'tuple'>
print(t[0]) # Output: 1
print(t[:2]) # Output: (1, 2)
print(t[2:]) # Output: (3, 4)
# Tuple cannot be modified

#Dictionary (dict)
d = {'a':1, 'b':2, 'c':3}
print(d) # Output: {'a': 1, 'b': 2, 'c': 3}
print(type(d)) # Output: <class 'dict'>
print(d['a']) # Output: 1
print(d['b']) # Output: 2
print(d['c']) # Output: 3
# Dictionary is a key-value pair data structure

#Set (set)
s = {1, 2, 3, 4}
print(s) # Output: {1, 2, 3, 4}
print(type(s)) # Output: <class 'set'>
# Set is a collection of unique elements

#None (NoneType)
n = None
print(n) # Output: None
print(type(n)) # Output: <class 'NoneType'>
# None is used to define a null value, or no value at all

#Complex (complex)
c = 1 + 2j
print(c) # Output: (1+2j)
print(type(c)) # Output: <class 'complex'>
# Complex numbers are written with a "j" as the imaginary part
# Complex numbers are not used much in Python programming

#Bytes (bytes)
b = b'Hello'
print(b) # Output: b'Hello'
print(type(b)) # Output: <class 'bytes'>
# Bytes are used to store binary data
# Bytes are immutable

#Bytearray (bytearray)
b = bytearray(5)
print(b) # Output: bytearray(b'\x00\x00\x00\x00\x00')
print(type(b)) # Output: <class 'bytearray'>
# Bytearray is a mutable version of bytes

#Frozen set (frozenset)
x = frozenset({"apple", "banana", "cherry"})
print(x) # Output: frozenset({'banana', 'cherry', 'apple'})
print(type(x)) # Output: <class 'frozenset'>
# Frozenset is a new class that has the characteristics of a set, but its elements cannot be changed once assigned
# While tuple are immutable lists, frozensets are immutable sets

#Range (range)
r = range(5)
print(r) # Output: range(0, 5)
print(type(r)) # Output: <class 'range'>
# Range is used to generate a sequence of numbers
# Range is immutable

