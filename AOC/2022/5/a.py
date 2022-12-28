
lines = []
with open('input.txt') as file:
    lines = file.read().splitlines()

boxOn = True
boxtmp = []
move = []
for line in lines:
    if line == '':
        boxOn = False
    else:
        if boxOn:
            boxtmp.append(line.split(' '))
        else:
            move.append(line.split(' '))

boxes = []
for i in range(int(len(boxtmp[-1])/3)):
    boxes.append([])


boxtmp.pop()

for box in boxtmp:
    j = 0
    empty = 0
    for i in box:
        if i != '':
            boxes[j].append(i[1:-1])
            j += 1
        else: 
            empty += 1
            if empty%4 == 0:
                empty = 0
                j += 1

for i in range(len(boxes)):
    boxes[i].reverse()
            

for m in move:
    numMove = int(m[1])
    f = int(m[3])-1
    t = int(m[5])-1
    print(boxes)
    for i in range(numMove):
        boxes[t].append(boxes[f][-1])
        boxes[f].pop()

ans = ''
for box in boxes:
    ans += box[-1]
print(ans)

