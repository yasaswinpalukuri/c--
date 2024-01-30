# This file contains the basic syntax of Python programming language
# Python is a case-sensitive language
# Python is an object-oriented language
# Python is an interpreted language

# Python Syntax
print("Hello, World!")

# indenration
if 5 > 2:
  print("Five is greater than two!")

# Variables
x = 4       # x is of type int
x = "Sally" # x is now of type str
print(x)


# Casting
x = str(3)    # x will be '3'
y = int(3)    # y will be 3
z = float(3)  # z will be 3.0


# Get the type
x = 5
y = "John"
print(type(x))
print(type(y))


# Single or Double Quotes for Strings
x = "John"
# is the same as
x = 'John'



# Case-Sensitive
a = 4
A = "Sally"
#A will not overwrite a


# Assigning multiple values
x, y, z = "Orange", "Banana", "Cherry"
print(x)
print(y)
print(z)

x = y = z = "Orange"
print(x)
print(y)
print(z)

fruits = ["apple", "banana", "cherry"]
x, y, z = fruits
print(x)
print(y)
print(z)

x = "Python"
y = "is"
z = "awesome"
print(x, y, z)

x = "Python "
y = "is "
z = "awesome"
print(x + y + z)


x = 5
y = "John"
print(x, y) # print(x+y) will give error



x = "awesome"

def myfunc():
  x = "fantastic"
  print("Python is " + x)

myfunc()

print("Python is " + x)


x = "awesome"

def myfunc():
  global x # same as declaring at the beginning of the file and make changes to the global variable
  x = "fantastic"

myfunc()

print("Python is " + x)