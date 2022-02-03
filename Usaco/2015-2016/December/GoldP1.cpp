#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[100001];

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	vector<int> e1(n/2), e2(n/2), b1, b2;
	for (int i = 0; i < n/2; i++) {
		cin >> e1[i];
		vis[e1[i]] = true;
	}
	for (int i = 0; i < n/2; i++) {
		cin >> e2[i];
		vis[e2[i]] = true;
	}
	int added = 0;
	for (int i = 1; i <= 2*n; i++) {
		if (vis[i]) continue;
		if (added >= n/2)
			b1.push_back(i);
		else 
			b2.push_back(i);
		added++;
	}
	sort(e1.rbegin(), e1.rend());
	sort(e2.begin(), e2.end());
	sort(b1.rbegin(), b1.rend());
	sort(b2.begin(), b2.end());
	int ans = 0;
	int l = 0, r = 0;
	while (l != n/2 && r != n/2) {
		if (e1[l] > b1[r]) 
			l++;
		else 
			ans++, l++, r++;
	}
	l = 0, r = 0;
	while (l != n/2 && r != n/2) {
		if (e2[l] < b2[r]) 
			l++;
		else 
			ans++, l++, r++;
	}
	cout << ans << '\n';
}

// two pointers for both low and high 
