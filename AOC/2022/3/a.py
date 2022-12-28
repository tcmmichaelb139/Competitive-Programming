#!/usr/bin/env python3
import sys

lines = [line.split() for line in sys.stdin]


ans = 0
for line in lines:
    line = line[0]
    left = line[:int(len(line)/2)]
    right = line[int(len(line)/2):]
    done = []
    for i in left:
        if i in right and not(i in done):
            done.append(i)
            if i.isupper():
                ans += ord(i) - ord('A') + 27
            else:
                ans += ord(i) - ord('a') + 1
print(ans)
            
