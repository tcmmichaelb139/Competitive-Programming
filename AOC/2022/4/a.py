import sys

lines = [line.strip() for line in sys.stdin]

assigned = []

for line in lines:
    tmp = line.split(',')
    assigned.append([tmp[0].split('-'), tmp[1].split('-')])
ans = 0
for a in assigned:
    if int(a[0][0]) >= int(a[1][0]) and int(a[0][0]) <= int(a[1][1]):
        ans += 1
    elif int(a[0][1]) >= int(a[1][0]) and int(a[0][1]) <= int(a[1][1]):
        ans += 1
    elif int(a[1][0]) >= int(a[0][0]) and int(a[1][0]) <= int(a[0][1]):
        ans += 1
    elif int(a[1][1]) >= int(a[0][0]) and int(a[1][1]) <= int(a[0][1]):
        ans += 1
print(ans)
    
