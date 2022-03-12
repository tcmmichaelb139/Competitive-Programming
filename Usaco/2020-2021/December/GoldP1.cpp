#include<bits/stdc++.h>
using namespace std;

int n, d;
vector<pair<int, int>> start;
char ar[1001][1001];
bool vis[1001][1001];
bool sol[1001][1001];
int dist[1001][1001];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int between(pair<int, int> k) {
    if (k.first < 0 || k.first >= n || k.second < 0 || k.second >= n) 
        return false;
    return true;
}

bool work(pair<pair<int, int>, int> k) {
    if (!between({k.first.first-k.second, k.first.second-k.second}))
        return false;
    if (!between({k.first.first+k.second, k.first.second+k.second}))
        return false;
    int i1 = k.first.first, j = k.first.second-k.second;
    int i2 = k.first.first;
    if (ar[i1][j] == '#') return false;
    while (j < k.first.second) {
        i1--, j++;
        i2++;
        if (ar[i1][j] == '#') return false;
        if (ar[i2][j] == '#') return false;
    }
    i1 = k.first.first, j = k.first.second+k.second;
    i2 = k.first.first;
    if (ar[i1][j] == '#') return false;
    while (j > k.first.second) {
        i1--, j--;
        i2++;
        if (ar[i1][j] == '#') return false;
        if (ar[i2][j] == '#') return false;
    }
    i1 = k.first.first, j = k.first.second-k.second;
    i2 = k.first.first;
    sol[i1][j] = true;
    while (j < k.first.second) {
        i1--, j++;
        i2++;
        sol[i1][j] = true;
        sol[i2][j] = true;
    }
    i1 = k.first.first, j = k.first.second+k.second;
    i2 = k.first.first;
    sol[i1][j] = true;
    while (j > k.first.second) {
        i1--, j--;
        i2++;
        sol[i1][j] = true;
        sol[i2][j] = true;
    }
    //{{{ TLE ON TEST CASE 6
    /* for (int a = k.first.first-k.second; a <= k.first.first; a++) { */
    /*     for (int b = k.first.second-(a-(k.first.first-k.second)); b <= k.first.second+(a-(k.first.first-k.second)); b++) { */
    /*         if (ar[a][b] == '#') return false; */
    /*     } */
    /* } */
    /* for (int a = k.first.first+k.second; a > k.first.first; a--) { */
    /*     for (int b = k.first.second-(k.first.first+k.second-a); b <= k.first.second+(k.first.first+k.second-a); b++) { */
    /*         if (ar[a][b] == '#') return false; */
    /*     } */
    /* } */
    /* for (int a = k.first.first-k.second; a <= k.first.first; a++) { */
    /*     for (int b = k.first.second-(a-(k.first.first-k.second)); b <= k.first.second+(a-(k.first.first-k.second)); b++) { */
    /*         sol[a][b] = true; */
    /*     } */
    /* } */
    /* for (int a = k.first.first+k.second; a > k.first.first; a--) { */
    /*     for (int b = k.first.second-(k.first.first+k.second-a); b <= k.first.second+(k.first.first+k.second-a); b++) { */
    /*         sol[a][b] = true; */
    /*     } */
    /* } */
    //}}}
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 'S')
                start.push_back({i, j});
        }
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < start.size(); i++)
        q.push({0, start[i]}), vis[start[i].first][start[i].second] = true;
    while (!q.empty()) {
        pair<int, pair<int, int>> k = q.front();
        q.pop();
        if (!(dist[k.second.first][k.second.second]%d) && dist[k.second.first][k.second.second] != 0) 
            k.first++;
        if (!work({k.second, k.first}))
            continue;
        /* cout << dist[k.second.first][k.second.second] << ' ' << k.second.first << ' ' << k.second.second << ' ' << k.first << '\n'; */
        for (int i = 0; i < 4; i++) {
            pair<int, pair<int, int>> x = k;
            x.second.first += dx[i], x.second.second += dy[i];
            if (!between(x.second))
                continue;
            if (!vis[x.second.first][x.second.second] && work({x.second, x.first})) {
                vis[x.second.first][x.second.second] = true;
                dist[x.second.first][x.second.second] = dist[k.second.first][k.second.second]+1;
                q.push(x);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (sol[i][j])
                ans++;
    cout << ans << '\n';
}

