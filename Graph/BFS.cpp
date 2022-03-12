#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int n, m;
int ans_BFS = 0;

void BFS(int s) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i); visited[i]=true;
            while (!q.empty()) {
                int s = q.front(); q.pop();
                for (int i = 0; i < edge[s].size(); i++) {
                    int e = edge[s][i];
                    if (!visited[e]) {
                        q.push(e); visited[e]=true;
                    }
                }
            }
            ans_BFS++;
        }
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
    BFS(0);
    cout << ans_BFS;
}
