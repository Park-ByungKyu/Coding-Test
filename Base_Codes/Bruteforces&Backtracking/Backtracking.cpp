#include <bits/stdc++.h>
using namespace std;

void pick (int n, vector<int>& picked, int topick) {
    if (!topick) {
        for (int i = 0; i < picked.size(); i++) {
            cout << picked[i] << ' ';
        } cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        picked.push_back(i);
        pick(n, picked, topick-1);
        picked.pop_back();
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> picked;
    pick(n, picked, m);
}
