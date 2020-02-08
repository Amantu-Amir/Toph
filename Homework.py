import math
def solve(s, l):
    sub, idx = [], 0
    for i in range((1 << l)):
        tmp = ""
        for j in range(l):
            if i & (1 << j):
                tmp += s[j]
        sub.append(tmp)
    return sub


def isPerfect(n):
    a = int(math.sqrt(n))
    if (a*a)==n:
        return True
    else:
        return False

#main fun
tc = int(input())
for i in range(tc):
    s = input()
    res = -1
    sub = solve(s, len(s))
    l = len(sub)
    ok = False
    for i in range(1,l):
        aa = int(sub[i])
        if isPerfect(aa) is True and aa != 0:
            ok = True
            ll = len(sub[i])-(len(sub[i])-len(str(aa)))
            res = max(res, ll)
    if ok is False:
        print("-1")
    else:
        print(len(s)-res)

