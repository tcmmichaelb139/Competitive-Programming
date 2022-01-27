#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
	freopen("cowfind.in", "r", stdin);
	freopen("cowfind.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	vector<int> b;
	for (int i = 0; i < s.length()-1; i++) 
		if (s[i] == '(' && s[i+1] == '(')
			b.push_back(i);
	long long ans = 0;
	for (int i = 0; i < s.length()-1; i++) 
		if (s[i] == ')' && s[i+1] == ')') {
			ans += (lower_bound(b.begin(), b.end(), i)-b.begin());
		}
	cout << ans << '\n';
}
