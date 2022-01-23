#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	set<int> curr;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < n && !curr.count(v[j])) {
			curr.insert(v[j]);
			j++;
		}
		ans = max(ans, j-i);
		if (curr.count(v[i]) == 1) 
			curr.erase(v[i]);

	}
	cout << ans << '\n';
}

