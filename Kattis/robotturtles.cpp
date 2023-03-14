#include "bits/stdc++.h"
using namespace std;

struct Node {
    int x, y;
    int dir;  // 0 - north, 1 - east, 2 - south, 3 - west
    string s;

    bool operator<(const Node& rhs) const {
        return s.length() > rhs.s.length();
    }
};

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 8;
    vector<vector<char>> ar(n, vector<char>(n));
    pair<int, int> start;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 'T')
                start = {i, j};
        }

    vector<vector<vector<int>>> vis(n, vector<vector<int>>(n, vector<int>(4)));

    priority_queue<Node> q;
    q.push({start.first, start.second, 1, ""});

    while (!q.empty()) {
        Node v = q.top();
        q.pop();

        if (ar[v.x][v.y] == 'D') {
            cout << v.s << '\n';
            return 0;
        }

        if (vis[v.x][v.y][v.dir]) continue;
        vis[v.x][v.y][v.dir] = true;

        Node left = v;
        left.dir = (left.dir + 3) % 4;
        left = {left.x + dx[left.dir], left.y + dy[left.dir], left.dir, left.s + "L"};
        if (left.x >= 0 && left.x < n && left.y >= 0 && left.y < n && ar[left.x][left.y] != 'C')
            if (!vis[left.x][left.y][left.dir]) {
                if (ar[left.x][left.y] == 'I')
                    left.s += 'X';
                left.s += 'F';
                q.push(left);
            }

        Node right = v;
        right.dir = (right.dir + 1) % 4;
        right = {right.x + dx[right.dir], right.y + dy[right.dir], right.dir, right.s + 'R'};
        if (right.x >= 0 && right.x < n && right.y >= 0 && right.y < n && ar[right.x][right.y] != 'C')
            if (!vis[right.x][right.y][right.dir]) {
                if (ar[right.x][right.y] == 'I')
                    right.s += 'X';
                right.s += 'F';
                q.push(right);
            }

        Node forw = v;
        forw = {forw.x + dx[forw.dir], forw.y + dy[forw.dir], forw.dir, forw.s};
        if (forw.x >= 0 && forw.x < n && forw.y >= 0 && forw.y < n && ar[forw.x][forw.y] != 'C')
            if (!vis[forw.x][forw.y][forw.dir]) {
                if (ar[forw.x][forw.y] == 'I')
                    forw.s += 'X';
                forw.s += 'F';
                q.push(forw);
            }
    }
    cout << "no solution\n";
}
