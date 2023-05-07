#include "bits/stdc++.h"
using namespace std;

struct Node {
    int l, r;
    long long sum;

    bool operator<(const Node& rhs) const {
        return sum < rhs.sum;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + v[i - 1];

    vector<Node> subar;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            subar.push_back({i, j - 1, pref[j] - pref[i]});
        }
    }

    sort(begin(subar), end(subar));

    for (int i = 0; i < n; i++) {
        vector<long long> cont;
        vector<long long> no;
        for (int j = 0; j < subar.size(); j++) {
            if (i >= subar[j].l && i <= subar[j].r)
                cont.push_back(subar[j].sum);
            else
                no.push_back(subar[j].sum);
        }

        long long ans = 1e18;

        int j1 = 0, j2 = 0;
        while (j1 < cont.size() && j2 < no.size()) {
            ans = min(ans, abs(cont[j1] - no[j2]));
            if (cont[j1] < no[j2])
                j1++;
            else
                j2++;
        }

        cout << ans << '\n';
    }
}
