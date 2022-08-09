#include "bits/stdc++.h"
using namespace std;

int g(int k) {
    return k ^ (k >> 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int start = 1;
    for (int i = 0; i < (1 << n); i++) {
        int k = g(i);
        for (int j = n - 1; j >= 0; j--) {
            if (k & (1 << j))
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
}
