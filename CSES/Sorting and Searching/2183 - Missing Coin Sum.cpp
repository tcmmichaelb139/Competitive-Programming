#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long x = 1;
	for (int i = 0; i < n; i++) {
		if (x < v[i]) break;
		x += v[i];
	}
	cout << x << '\n';
}
