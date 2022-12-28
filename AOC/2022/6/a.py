
line = open("input.txt", "r").read()
print(line)

for i in range(len(line)-4):
    l = []
    for j in range(i, i+4):
        if not l.count(line[j]):
            l.append(line[j])
    print(l)
    if len(l) == 4:
        print(i+4)
        break

