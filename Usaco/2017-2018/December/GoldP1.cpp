#include<bits/stdc++.h>
using namespace std;

long long n, d;
long long dist[100001][2];
bool vis[100001][2];

int main() {
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> d;
    vector<pair<long long, long long>> bn(n), en(n);
    vector<pair<pair<long long, long long>, long long>> b(n), e(n);
    vector<pair<long long, bool>> start; // 0 = bessie, 1 = elsie
    for (int i = 0; i < n; i++) {
        cin >> b[i].first.second >> b[i].first.first;
        b[i].second = i;
        bn[i] = b[i].first;
        if (b[i].first.first == 0) 
            start.push_back({i, 0});
        dist[i][0] = dist[i][1] = 1e9;
    }
    for (int i = 0; i < n; i++) {
        cin >> e[i].first.first >> e[i].first.second;
        e[i].second = i;
        en[i] = e[i].first;
        if (e[i].first.first == 0) 
            start.push_back({i, 1});
    }
    sort(begin(b), end(b));
    sort(begin(e), end(e));
    queue<pair<long long, bool>> q;
    for (int i = 0; i < start.size(); i++) 
        q.push(start[i]), vis[start[i].first][start[i].second] = true
            , dist[start[i].first][start[i].second] = 1;
    while (!q.empty()) {
        pair<long long, bool> k = q.front();
        q.pop();
        if (k.second) {
            //run bessie
            auto it1 = lower_bound(begin(b), end(b), make_pair(make_pair(en[k.first].second-d, 0LL), 0LL));
            auto it2 = upper_bound(begin(b), end(b), make_pair(make_pair(en[k.first].second, (long long)1e9), (long long)1e9));
            for (auto it = it1; it != it2; it++) {
                if (!vis[(*it).second][0]) {
                    vis[(*it).second][0] = true;
                    dist[(*it).second][0] = dist[k.first][1]+1;
                    q.push({(*it).second, false});
                }
            }
        } else {
            //run elsie
            auto it1 = lower_bound(begin(e), end(e), make_pair(make_pair(bn[k.first].second-d, 0LL), 0LL));
            auto it2 = upper_bound(begin(e), end(e), make_pair(make_pair(bn[k.first].second, (long long)1e9), (long long)1e9));
            for (auto it = it1; it != it2; it++) {
                if (!vis[(*it).second][1]) {
                    vis[(*it).second][1] = true;
                    dist[(*it).second][1] = dist[k.first][0]+1;
                    q.push({(*it).second, true});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) 
        cout << (dist[i][0] == 1e9 ? -1 : dist[i][0]) << '\n';
}

