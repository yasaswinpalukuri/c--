def math_chair(n,a):
    for i in range(n):
        b= a[i:]+a[:i]
        ap = 0
        k = 0
        for c in b:
            dis = c[0]
            app = c[1] + ap
            if dis > app:
                break
            else:
                ap = app-dis
            k += 1
            if k == len(a):
                return(i+1)

n = int(input())
arr = []
for i in range(n):
    a = list(map(int, input().split()))
    arr.append(a)
    
print(math_chair(n,arr))