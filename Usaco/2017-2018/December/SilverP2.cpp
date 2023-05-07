#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long g;
    cin >> n >> g;
    set<int> days;
    set<int> ids;
    map<int, pair<int, int>> changes;
    for (int i = 0; i < n; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        days.insert(a);
        ids.insert(b);
        changes[a] = {b, c};
    }

    map<int, long long> idVal;

    map<long long, int> numVal;

    multiset<pair<long long, int>> vals;

    for (auto id : ids) {
        vals.insert({g, id});
        idVal[id] = g;
        numVal[g]++;
    }

    int ans = 0;

    for (auto day : days) {
        long long curHigh = (--end(vals))->first;
        long long curHighId = (--end(vals))->second;

        int curID = changes[day].first, change = changes[day].second;

        long long curVal = idVal[curID];
        vals.erase(vals.find({curVal, curID}));
        numVal[curVal]--;

        long long newVal = curVal + change;
        vals.insert({newVal, curID});
        idVal[curID] = newVal;
        numVal[newVal]++;

        long long newHigh = (--end(vals))->first;
        long long newHighId = (--end(vals))->second;

        if (curHigh != newHigh && (numVal[curHigh] + 1 != numVal[newHigh] || curHighId != newHighId))
            ans++;
        if (curHigh == newHigh && (newVal == newHigh || curVal == newHigh))
            ans++;
    }

    cout << max(ans, 1) << '\n';
}
