def qu(a,b):
    if (a,b) not in d:
        print("?", a+1,b+1)
        d[(a,b)] = int(input())
    return d[(a,b)]
for _ in range(int(input())):
    d = dict()
    n = int(input())
    SOL = ["0"] * n
    last = qu(0,n-1)
    if last:
        z = 1
        for i in range(n-2,0,-1):
            nw= qu(0,i)
            if nw != last:
                SOL[i+1] = "1"
            last = nw
            if last == 0:
                z = i+1;break
        if last:
            SOL[1] = "1"
            SOL[0] = "0"
        else:
            last = 1
            for j in range(z-2,-1,-1):
                nw = qu(j,z)
                if nw == last:
                    SOL[j] = "1"
                last = nw
        print("!","".join(SOL))
    else:
        print("! IMPOSSIBLE")