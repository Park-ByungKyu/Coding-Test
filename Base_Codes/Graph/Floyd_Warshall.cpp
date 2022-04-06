#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> edge;

void Floyd_Warshall (int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && edge[i][k] + edge[k][j] < edge[i][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edge[i][j] == INT_MAX) cout << "0" << ' ';
            else cout << edge[i][j] << ' ';
        } cout << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    edge.resize(n, vector<ll>(n, INT_MAX));
    int s, e, cost;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> cost;
        s--; e--;
        if (edge[s][e] > cost) edge[s][e] = cost;
    }
    Floyd_Warshall(n);
}
