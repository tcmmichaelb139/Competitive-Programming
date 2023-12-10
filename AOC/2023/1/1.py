inp = open("input", "r").read().splitlines()

ans = 0

spell = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]


for i in inp:
    first = "-1"
    last = "-1"
    for j in range(len(i)):
        for k in range(1, len(spell)):
            if i[j : j + len(spell[k])] == spell[k]:
                if first == "-1":
                    first = k
                last = k
        if i[j].isdigit():
            if first == "-1":
                first = i[j]
            last = i[j]
    print(i, first, last)
    ans += int(first) * 10 + int(last)

print(ans)
