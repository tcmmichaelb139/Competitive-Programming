// 11/13 test cases
#include<bits/stdc++.h>
using namespace std;

int n, k;
int v[50002];
int vadj[50002];
bool vis[50002];
vector<int> adj[52];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	for (int i = 0; i < k; i++) {
		string s; cin >> s;
		for (int j = 0; j < k; j++)
			if (s[j]-'0') {
				for (int a = 0; a < n; a++) 
					if (j+1 == v[a]) {
						adj[i+1].push_back(a);
					}
			}
	}
	priority_queue<pair<long long, long long>,
		vector<pair<long long, long long>>,
		greater<pair<long long, long long>>> q; // dist, index
	q.push({0, 0});
	while (!q.empty()) {
		pair<long long, long long> k = q.top();
		q.pop();
		if (k.second == n-1) {
			cout << k.first << '\n';
			return 0;
		}
		if (vis[k.second]) continue;
		vis[k.second] = true;
		for (auto i: adj[v[k.second]]) {
			q.push({k.first+abs(k.second-i), i});
		}
	}
	cout << -1 << '\n';
}
