/*
ID: tcmmich1
TASK: msquare
LANG: C++
 */
#include "bits/stdc++.h"
using namespace std;

struct node {
    vector<int> v;
    string ans;

    bool operator<(const node &rhs) const {
        if (ans.length() == rhs.ans.length())
            return ans > rhs.ans;
        return ans.length() > rhs.ans.length();
    }
};

int main() {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(8);
    for (int i = 0; i < 8; i++) {
        cin >> v[i];
        v[i]--;
    }

    vector<int> ideal = {0, 1, 2, 3, 4, 5, 6, 7};

    priority_queue<node> q;
    q.push({ideal, ""});

    auto test1 = [&](vector<int> prev) {
        vector<int> cur = prev;
        for (int i = 0; i < 4; i++)
            swap(cur[i], cur[7 - i]);
        return cur;
    };

    auto test2 = [&](vector<int> prev) {
        vector<int> cur = prev;
        for (int i = 0; i < 4; i++)
            cur[i] = prev[(i + 3) % 4], cur[i + 4] = prev[(i + 1) % 4 + 4];
        return cur;
    };

    auto test3 = [&](vector<int> prev) {
        vector<int> cur = prev;
        cur[1] = prev[6];
        cur[6] = prev[5];
        cur[5] = prev[2];
        cur[2] = prev[1];
        return cur;
    };

    map<vector<int>, bool> vis;

    while (!q.empty()) {
        node u = q.top();
        q.pop();

        if (vis.find(u.v) != vis.end()) continue;
        vis[u.v] = true;

        if (u.v == v) {
            cout << u.ans.length() << '\n';
            cout << u.ans << '\n';
            break;
        }

        vector<int> t1 = test1(u.v);
        if (vis.find(t1) == vis.end()) {
            q.push({t1, u.ans + 'A'});
        }

        vector<int> t2 = test2(u.v);
        if (vis.find(t2) == vis.end()) {
            q.push({t2, u.ans + 'B'});
        }

        vector<int> t3 = test3(u.v);
        if (vis.find(t3) == vis.end()) {
            q.push({t3, u.ans + 'C'});
        }
    }
}
