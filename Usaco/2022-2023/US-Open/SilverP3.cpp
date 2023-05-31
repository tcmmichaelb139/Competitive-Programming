#include "bits/stdc++.h"
using namespace std;

const string BESSIE = "bessie";

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	long long ans = 0;
	vector<long long> numLen(BESSIE.length() + 1, 0);
	for (long long i = 0; i < s.length(); i++) {
		numLen[0]++;
		for (int j = 5; j >= 0; j--) {
			if (BESSIE[j] == s[i]) {
				numLen[j + 1] += numLen[j];
				numLen[j] = 0;
			}
		}
		ans += numLen[6] * (s.length() - i);
		numLen[0] += numLen[6];
		numLen[6] = 0;
	}

	cout << ans << '\n';
}
