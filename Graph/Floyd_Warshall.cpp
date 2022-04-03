#include <bits/stdc++.h>
using namespace std;

void Floyd_Warshall (int n, vector<vector<int>>& edge) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i!=j && edge[i][k]!=-1 && edge[k][j]!=-1 && 
                    (edge[i][k] + edge[k][j] < edge[i][j] || edge[i][j] == -1)) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edge[i][j]==-1) cout << "0" << ' ';
            else cout << edge[i][j] << ' ';
        } cout << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge;
    edge.resize(n, vector<int>(n, -1));
    int s, e, cost;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> cost;
        s--; e--;
        if (edge[s][e]==-1 || edge[s][e] > cost) edge[s][e] = cost;
    }
    Floyd_Warshall(n, edge);
}
