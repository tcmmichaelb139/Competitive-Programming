/*
ID: tcmmich1
LANG: C++
TASK: zerosum
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> ans;

void dfs(vector<char> curr, int index, int size, int before, bool sign) {
	if (index == n+1) {
		/* cout << 1; */
		/* for (int i = 0; i < curr.size(); i++)  */
		/* 	cout << curr[i] << i+2; */
		/* cout << '\n'; */
		if (size == 0)
			ans.push_back(curr);
		return;
	}
	vector<char> curr1, curr2, curr3 = curr2 = curr1 = curr;
	curr1.push_back('+');
	dfs(curr1, index+1, size+index, index, true);
	curr2.push_back('-');
	dfs(curr2, index+1, size-(index), index, false);
	curr3.push_back(' ');
	string ks = to_string(before)+to_string(index);
	int k = stoi(ks);
	if (sign)
		dfs(curr3, index+1, (size-before)+k, k, true);
	else
		dfs(curr3, index+1, (size+before)-k, k, false);
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> n;
	dfs(vector<char>(), 2, 1, 1, true);
	vector<string> sol;
	for (int i = 0; i < ans.size(); i++) {
		string k = "1";
		for (int j = 0; j < ans[i].size(); j++) 
			k += ans[i][j]+to_string(j+2);
		sol.push_back(k);
	}
	sort(sol.begin(), sol.end());
	for (auto i: sol)
		cout << i << '\n';
}

/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

