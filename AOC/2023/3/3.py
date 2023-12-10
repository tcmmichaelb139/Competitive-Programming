inp = open("input", "r").read().splitlines()

ans = 0

for i in range(len(inp)):
    line = inp[i]
    cur = ""
    for j in range(len(line)):
        char = line[j]

        if char.isdigit():
            cur += char
        else:


