#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	map<int, pair<int, int>> vals;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < i - 1; j++)
			vals[v[i - 1] + v[j]] = {i - 1, j};

		for (int j = i + 1; j < n; j++) {
			int rem = x - v[i] - v[j];
			if (vals.find(rem) != vals.end()) {
				pair<int, int> oth = vals[rem];
				cout << i + 1 << ' ' << j + 1 << ' ' << oth.first + 1 << ' ' << oth.second + 1 << '\n';
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
