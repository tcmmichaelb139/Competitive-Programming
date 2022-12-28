
line = open("input.txt", "r").read()
print(line)

for i in range(len(line)-14):
    l = []
    for j in range(i, i+14):
        if not l.count(line[j]):
            l.append(line[j])
    print(l)
    if len(l) == 14:
        print(i+14)
        break

