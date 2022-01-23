/*
ID: tcmmich1
TASK: fact4
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	
	cin >> n;
	int currlast = 1;
	for (int i = 2; i <= n; i++) {
		int ii = i;
		while (ii%10 == 0)
			ii /= 10;
		currlast *= ii;
		while (currlast%10 == 0)
			currlast /= 10;
		if (currlast > 999)
			currlast %= 1000;
	}
	cout << currlast%10 << '\n';
}
