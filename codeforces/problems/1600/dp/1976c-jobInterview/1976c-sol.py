for _ in range(int(input())):
    n, m = map(int, input().split())
    bounds = [n, m]
    a = []
    a.append(list(map(int, input().split())))
    a.append(list(map(int, input().split())))
    
    bad = -1
    badType = -1
    cur = [0, 0]
    ans = 0
    types = [0 for i in range(n + m + 1)]
    for i in range(n + m):
        curType = 0
        if a[0][i] < a[1][i]:
            curType = 1
        if cur[curType] == bounds[curType]:
            curType = 1 - curType
            if bad == -1:
                bad = i
                badType = 1 - curType
        types[i] = curType
        ans += a[curType][i]
        cur[curType] += 1
        
    res = []
    for i in range(n + m):
        val = ans - a[types[i]][i]
        if bad != -1 and i < bad and types[i] == badType:
            val = val + a[badType][bad] - a[1 - badType][bad] + a[1 - badType][n + m]
        else:
            val = val + a[types[i]][n + m]
        res.append(val)
    res.append(ans)
    print(*res)