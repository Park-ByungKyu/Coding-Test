#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int n, m;
int ans_DFS = 0;

void DFS(int s) {
    visited[s] = true;
    for (int i = 0; i < edge[s].size(); i++) {
        int e = edge[s][i];
        if (!visited[e]) DFS(e);
    }
}

void DFS_all() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {DFS(i); ans_DFS++;}
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    edge.resize(n, vector<int>());
    int a,b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    visited.resize(n,false);
    DFS_all();
    cout << ans_DFS;
}
