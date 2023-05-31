#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	string ans = "";
	int cur = 0;
	int dir = 1;
	while (true) {
		if (v[cur] == 0) break;
		if (dir == -1)
			ans += "L";
		else
			ans += "R";
		if ((cur == 0 && dir == -1) || (cur == n - 1 && dir == 1)) {
			v[cur]--;
			dir *= -1;
		} else if (v[cur + dir] == 1 && v[cur] != 1) {
			v[cur]--;
			dir *= -1;
		} else if (v[cur + dir] == 0) {
			v[cur]--;
			dir *= -1;
		} else {
			v[cur]--;
			cur += dir;
		}
	}
	cout << ans << '\n';
}
