#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<pair<int,ll>>> edge;
vector<bool> visited;
vector<ll> dist;

void Dijkstra (int n, int start) {
    dist[start] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,start});
    
    while (!pq.empty()) {
        int s;
        do {
            s = pq.top().second;
            pq.pop();
        } while (!pq.empty() && visited[s]);
        if (visited[s]) break;

        visited[s] = true;
        for (int i = 0; i < edge[s].size(); i++) {
            int e = edge[s][i].first;
            ll c = edge[s][i].second;
            if (dist[e] > dist[s]+c) {
                pq.push({dist[s]+c, e});
                dist[e] = dist[s]+c;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dist[i]==INT_MAX) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    int start; cin >> start; start--;
    edge.resize(n, vector<pair<int,ll>>());
    visited.resize(n, false);
    dist.resize(n, INT_MAX);
        
    int s, e; ll cost;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> cost;
        s--; e--;
        edge[s].push_back({e, cost});
    }
    Dijkstra(n, start);
}
