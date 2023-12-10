inp = open("input", "r").read().splitlines()

ans = 0

for game in inp:
    game = game.split(":")

    gameNum = [int(s) for s in game[0].split() if s.isdigit()][0]
    sets = [s.strip() for s in game[1].split(";")]
    rgb = dict({"red": 0, "green": 0, "blue": 0})
    for se in sets:
        se = [s.strip() for s in se.split(",")]
        for s in se:
            s = s.split(" ")
            rgb[s[1]] = max(rgb[s[1]], int(s[0]))

    rgbGood = dict({"red": 12, "green": 13, "blue": 14})

    ok = True
    for i in ["red", "green", "blue"]:
        if rgbGood[i] < rgb[i]:
            ok = False

    if ok:
        ans += gameNum

print(ans)
