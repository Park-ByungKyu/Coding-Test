#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n; cin >> n;
    int like[n*n][5];
    for (int i = 0; i < n*n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> like[i][j]; like[i][j]--;
        }
    }
    vector<int> likeind[n*n];
    for (int i = 0; i < n*n; i++) {
        for (int j = 0; j < 4; j++) {
            likeind[like[i][0]].push_back(like[i][j+1]);
        }
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int empty_cnt[n][n];
    int sitted[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            empty_cnt[i][j]=0; sitted[i][j]=-1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i+dx[k]; int nj = j+dy[k];
                if (ni>-1&&ni<n&&nj>-1&&nj<n) empty_cnt[i][j]++;
            }
        }
    }
    for (int p = 0; p < n*n; p++) {
        int ind = like[p][0];
        int likecnt[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) likecnt[i][j]=0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (sitted[i][j]!=-1) {
                    for (int k = 1; k <= 4; k++) {
                        if (like[p][k] == sitted[i][j]) {
                            for (int l = 0; l < 4; l++) {
                                int ni=i+dx[l]; int nj=j+dy[l];
                                if (ni>-1&&ni<n&&nj>-1&&nj<n) likecnt[ni][nj]++;
                            }
                        }
                    }
                }
            }
        }
        vector<pair<int,int>> v1[5][5]; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (sitted[i][j]==-1)v1[likecnt[i][j]][empty_cnt[i][j]].push_back({i,j});
            }
        } 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                sort(v1[i][j].begin(), v1[i][j].end());
            }
        }
        int tox,toy; int tag = 0;
        for (int p = 4; p >= 0; p--) {
            for (int q = 4; q >= 0; q--) {
                if (v1[p][q].size()!=0) {
                    tox = v1[p][q][0].first; toy = v1[p][q][0].second;
                    tag = 1; break;
                }
            } if (tag == 1) break;
        }
        sitted[tox][toy] = ind;
        for (int i = 0; i < 4; i++) {
            int nx = tox+dx[i]; int ny = toy+dy[i];
            if (nx>-1&&nx<n&&ny>-1&&ny<n) {
                empty_cnt[nx][ny]--;
            }
        }
    }
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            int ind = sitted[i][j];
            for (int k = 0; k < 4; k++) {
                int nx = i+dx[k]; int ny = j+dy[k];
                if (nx>-1&&nx<n&&ny>-1&&ny<n) {
                    for (int l = 0; l < 4; l++) {
                        if (likeind[ind][l] == sitted[nx][ny]) cnt++;
                    }
                }
            }
            if (cnt==1)score+=1;
            if (cnt==2)score+=10;
            if (cnt==3)score+=100;
            if (cnt==4)score+=1000;
        }
    }
    cout << score;
} 
