#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int shortest(vector<vector<int>>& board, int sx, int sy, int ex, int ey) {
    int dist[4][4];
    int dx[4] = {0,0,1,-1}; int dy[4] = {1,-1,0,0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dist[i][j] = 100;
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{sx,sy},0});
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        dist[x][y] = d;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (x+dx[i]>=0&&x+dx[i]<4&&y+dy[i]>=0&&y+dy[i]<4) {
                if (dist[x+dx[i]][y+dy[i]] > d+1) {
                    dist[x+dx[i]][y+dy[i]] = d+1;
                    q.push({{x+dx[i],y+dy[i]},d+1});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int newx = x; int newy = y;
            while (newx+dx[i]>=0&&newx+dx[i]<4&&newy+dy[i]>=0&&newy+dy[i]<4 && board[newx+dx[i]][newy+dy[i]]==0) {
                newx = newx+dx[i]; newy = newy+dy[i];
            }
            if (newx+dx[i]>=0&&newx+dx[i]<4&&newy+dy[i]>=0&&newy+dy[i]<4) {
                newx = newx+dx[i]; newy = newy+dy[i];
            }
            if (dist[newx][newy] > d+1) {
                dist[newx][newy] = d+1;
                q.push({{newx,newy},d+1});
            } 
        }
    }
    board[ex][ey] = 0;
    return dist[ex][ey];
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 2147483647;
    int cnt = 0;
    vector<pair<int,int>> pr[7];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                pr[board[i][j]].push_back({i,j});
            }
        }
    }
    vector<pair<int,int>> v;
    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < pr[i].size(); j++) {
            v.push_back(pr[i][j]);
        }
    }
    int n = v.size()/2;
    int comb2 = (1<<n);
    
    vector<int> pm;
    for (int i = 0; i < n; i++) pm.push_back(i);
    do {
        for (int i = 0; i < comb2; i++) {
            int tmp = i;
            vector<int> order;
            for (int j = 0; j < n; j++) {
                order.push_back(pm[j]*2+tmp%2);
                if (tmp%2==1)order.push_back(pm[j]*2);
                else order.push_back(pm[j]*2+1);
                tmp/=2;
            }
            int dst = 0;
            vector<vector<int>> brd = board;
            dst += shortest(brd, r,c,v[order[0]].first,v[order[0]].second);
            for (int i = 0; i < order.size()-1; i++) {
                dst += shortest(brd, v[order[i]].first,v[order[i]].second,
                v[order[i+1]].first,v[order[i+1]].second);
            }
            if (dst < answer) answer = dst;
        }
    } while (next_permutation(pm.begin(), pm.end()));
    answer += (n*2);
    return answer;
}
