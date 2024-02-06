# 0 1 1 2 3 5 8 . . ..  n terms
def fibonacci(n):
    a = 0
    b = 1
    if n == 1:
        print(a)
    else:
        print(a)
        print(b)
        for i in range(2, n):
            c = a + b
            a = b
            b = c
            print(c)

def main():
    n = int(input("Enter the number of terms: "))
    fibonacci(n)

if __name__ == "__main__":
    main()