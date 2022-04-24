#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n; cin >> n;
    int arr[n][n];
    int dist[n][n];
    pair<int,int> pos; 
    int fishcount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                pos.first = i;
                pos.second = j;
                arr[i][j]=0;
            }
            else if (arr[i][j] != 0) fishcount++;
            dist[i][j]=INT_MAX;
        }
    }
    int size = 2;
    int time = 0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    queue<pair<int,int>> q1;
    int eat = 0;

    while (true) {
        if (fishcount == 0) break;
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (size > arr[i][j] && arr[i][j] > 0) cnt++;
            }
        }
        if (cnt==0) break;
        q1.push(pos);
        dist[pos.first][pos.second]=0;
        while (!q1.empty()) {
            int x = q1.front().first;
            int y = q1.front().second;
            int dis = dist[x][y];
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int newx=x+dx[i]; int newy=y+dy[i];
                if (newx>-1 && newx<n && newy>-1 && newy<n && dist[newx][newy]>dis+1 && arr[newx][newy]<=size) {
                    dist[newx][newy]=dis+1;
                    q1.push(make_pair(newx,newy));
                }
            }
        }
        int mindist = INT_MAX; int gox = -1, goy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mindist > dist[i][j] && size > arr[i][j] && arr[i][j] > 0) {
                    mindist = dist[i][j]; gox=i; goy=j;
                }
            }
        }
        if (gox == -1) break;

        time += mindist;
        arr[gox][goy]=0;
        eat++;
        fishcount--;
        if (eat == size) {
            size++; eat=0;
        }
        pos.first=gox; pos.second=goy;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j]=INT_MAX;
            }
        }
    }
    cout << time;
} 
