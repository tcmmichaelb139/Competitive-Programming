#!/usr/bin/env python3
import sys

lines = [line.split() for line in sys.stdin]


ans = 0
group = []
for line in lines:
    line = line[0]
    group.append(line)
    if len(group) == 3:
        for i in group[0]:
            if i in group[1] and i in group[2]:
                if i.isupper():
                    ans += ord(i) - ord('A') + 27
                else:
                    ans += ord(i) - ord('a') + 1
                group.clear()
                break
print(ans)
            
