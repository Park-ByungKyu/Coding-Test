#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int m = fares.size();
    long long dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {dist[i][j]=2147483647;
                                     if (i==j) dist[i][j]=0;}
    } 
    for (int i = 0; i < m; i++) {
        int s = fares[i][0]-1; int e = fares[i][1]-1;
        int d = fares[i][2];
        dist[s][e]=d; dist[e][s]=d;
    }
    long long dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) dp[i][j] = dist[i][j];
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k]+dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k]+dp[k][j];
                }
            }
        }
    }
    answer = 2147483647;
    for (int g=0; g < n; g++) {
        int cost = 0;
        cost = dp[s-1][g]+dp[g][a-1]+dp[g][b-1];
        if (cost < answer) answer = cost;
    }
    return answer; 
}
