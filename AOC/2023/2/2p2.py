inp = open("input", "r").read().splitlines()

ans = 0

for game in inp:
    game = game.split(":")

    sets = [s.strip() for s in game[1].split(";")]
    rgb = dict({"red": 0, "green": 0, "blue": 0})
    for se in sets:
        se = [s.strip() for s in se.split(",")]
        for s in se:
            s = s.split(" ")
            rgb[s[1]] = max(rgb[s[1]], int(s[0]))

    ans += rgb["red"] * rgb["green"] * rgb["blue"]

print(ans)
