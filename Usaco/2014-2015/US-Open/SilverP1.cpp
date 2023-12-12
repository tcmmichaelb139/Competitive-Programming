#include "bits/stdc++.h"
using namespace std;

int main() {
	freopen("bgm.in", "r", stdin);
	freopen("bgm.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	map<int, int> idx = {{'B', 0}, {'E', 1}, {'S', 2}, {'I', 3}, {'G', 4}, {'O', 5}, {'M', 6}};
	vector<vector<long long>> cow(7, vector<long long>(7, 0));
	for (int i = 0; i < n; i++) {
		char c;
		int a;
		cin >> c >> a;
		cow[idx[c]][(a % 7 + 7) % 7]++;
	}

	auto mod7 = [](int x) { return x % 7 == 0; };

	long long ans = 0;
	for (int b = 0; b < 7; b++) {
		long long nb = cow[0][b];
		for (int e = 0; e < 7; e++) {
			long long ne = cow[1][e];
			for (int s = 0; s < 7; s++) {
				long long ns = cow[2][s];
				for (int i = 0; i < 7; i++) {
					long long ni = cow[3][i];
					for (int g = 0; g < 7; g++) {
						long long ng = cow[4][g];
						for (int o = 0; o < 7; o++) {
							long long no = cow[5][o];
							for (int m = 0; m < 7; m++) {
								long long nm = cow[6][m];
								if (nb && ne && ns && ni && ng && no && nm) {
									if (mod7(b + 2 * e + 2 * s + i) ||
									    mod7(g + o + e + s) ||
									    mod7(m + 2 * o)) {
										ans += nb * ne * ns * ni * ng * no * nm;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << ans << '\n';
}
