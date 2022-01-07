/*
ID: tcmmich1
TASK: contact
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int a, b, n;
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	
	cin >> a >> b >> n;
	string s, ss; 
	while (cin >> ss)
		s += ss;
	for (int i = 0; i < s.size(); i++) {
		for (int j = a; j <= b; j++) {
			if (j+i > s.size())
				continue;
			m[s.substr(i, j)]++;
		}
	}
	vector<pair<int, string>> v;
	for (auto i: m)
		v.push_back({i.second, i.first});
	sort(v.begin(), v.end(), [](pair<int, string> a, pair<int, string> b) {
			if (a.first == b.first) {
				if (a.second.length() == b.second.length())
					return a.second < b.second;
				else 
					return a.second.length() < b.second.length();
			}
			return a.first > b.first;
			});
	int num = 0;
	for (int i = 0; i < v.size(); i++) {
		num++;
		int to = i;
		while (to < v.size() && v[to].first == v[i].first)
			to++;
		cout << v[i].first << '\n';
		for (int a = i; a < to; a++)
			cout << v[a].second << " \n"[a+1 == to || (a-i+1)%6 == 0];
		i = to-1;
		if (num == n) break;
	}
}
