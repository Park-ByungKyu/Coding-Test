#include <bits/stdc++.h>
using namespace std;

void pick (int n, vector<int>& picked, int m, int topick) {
    if (topick == 0) {
        for (int i = 0; i < m; i++) {
            cout << picked[i] << ' ';
        } cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        picked.push_back(i);
        pick(n, picked, m, topick-1);
        picked.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> picked;
    pick(n, picked, m, m);
}
