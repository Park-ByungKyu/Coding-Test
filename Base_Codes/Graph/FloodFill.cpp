#include <bits/stdc++.h>
using namespace std;

void FloodFill(vector<vector<int>>& arr, int sr, int sc, int newColor) {
    int n = arr.size();
    int m = arr[0].size();
        
    int dx[4]={1,-1,0,0}; 
    int dy[4]={0,0,1,-1};
        
    bool visited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) visited[i][j]=false;
    }
    queue<pair<int,int>> q;
    int c = arr[sr][sc]; arr[sr][sc]=newColor;
    q.push({sr,sc}); visited[sr][sc]=true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i]; int ny = y+dy[i];
            if (nx>=0&&nx<n&&ny>=0&&ny<m&&visited[nx][ny]==false&&arr[nx][ny]==c) {
                visited[nx][ny]=true; arr[nx][ny]=newColor;
                q.push({nx,ny});
            }
        }
    }
}
