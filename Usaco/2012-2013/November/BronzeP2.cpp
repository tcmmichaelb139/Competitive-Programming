#include<bits/stdc++.h>
using namespace std;

string s; 

int main() {
	freopen("typo.in", "r", stdin);
	freopen("typo.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			sum++;
		} else {
			sum--;
		}
	}
	if (sum == 0) {
		cout << 0 << '\n';
		return 0;
	}
	if (sum > 0) { 
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				s[i] = ')';
			else
				s[i] = '(';
		}
	}
	int ans = 0;
	sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			ans++;
			sum--;
		} else 
			sum++;
		if (sum < 0)
			break;
	}
	cout << ans << '\n';
}
