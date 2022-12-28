#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto dist = [](pair<long long, long long> a, pair<long long, long long> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    auto angle = [](pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
        if (a.first == b.first) {
            if (a.second < b.second)
                if (b.first < c.first)
                    return 90;
            if (a.second > b.second)
                if (b.first > c.first)
                    return 90;
        } else {
            if (a.first < b.first)
                if (b.second > c.second)
                    return 90;
            if (a.first > b.first)
                if (b.second < c.second)
                    return 90;
        }
        return 270;
    };

    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<long long> best(n, 0);

    for (int i = 1; i < n; i++) {
        long long dist1 = 0, dist2 = 0;
        for (int j = i; j > 0; j--)
            dist1 += dist(v[j], v[j - 1]);

        for (int j = i; j < n; j++)
            dist2 += dist(v[j], v[(j + 1) % n]);

        best[i] = min(dist1, dist2);
    }

    map<vector<long long>, long long> m;

    for (int i = 1; i < n; i++) {
        vector<long long> cur;
        cur.push_back(angle(v[(i - 1) % n], v[i], v[(i + 1) % n]));

        m[cur]++;

        for (int j = i; j < n; j++) {
            cur.push_back(dist(v[j % n], v[(j + 1) % n]));
            cur.push_back(angle(v[j % n], v[(j + 1) % n], v[(j + 2) % n]));
            m[cur]++;
        }
    }

    long long mx = 0;
    for (int i = 1; i < n; i++) {
        vector<long long> cur;
        cur.push_back(angle(v[(i - 1) % n], v[i], v[(i + 1) % n]));

        long long trav = 0;
        bool done = false;

        for (int j = i; j < n; j++) {
            trav += dist(v[j % n], v[(j + 1) % n]);
            cur.push_back(dist(v[j % n], v[(j + 1) % n]));
            cur.push_back(angle(v[j % n], v[(j + 1) % n], v[(j + 2) % n]));

            if (m[cur] == 1) {
                mx = max(mx, (trav + best[(j + 1) % n]) - best[i]);
                done = true;
                break;
            }
        }
        if (!done)
            mx = max(mx, trav - best[i]);
    }

    cout << mx << '\n';
}
