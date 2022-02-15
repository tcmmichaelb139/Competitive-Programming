#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) 
		cin >> v[i];
	stack<pair<int, int>> s;
	s.push({0, 0});
	for (int i = 1; i <= n; i++) {
		while (s.top().first >= v[i]) s.pop();
		cout << s.top().second << " \n"[i == n];
		s.push({v[i], i});
	}
}
