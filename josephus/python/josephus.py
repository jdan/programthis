def josephus(count):
    a = range(1, count + 1)
    p = 0

    while len(a) > 1:
        a.remove(a[p])
        p += 1
        p %= len(a)
    
    return a[0]
    
for i in range(1, 20):
    print josephus(i)