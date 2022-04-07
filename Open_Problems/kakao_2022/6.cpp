#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    int change[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) change[i][j] = 0;
    }
    int k = skill.size();
    for (int i = 0; i < k; i++) {
        int p = skill[i][0];
        int x1 = skill[i][1]; int y1 = skill[i][2];
        int x2 = skill[i][3]; int y2 = skill[i][4];
        int degree = skill[i][5];
        
        if (p == 1) {
            change[x2][y2] -= degree;
            if (y2 >= 0 && x1-1 >= 0) change[x1-1][y2] += degree;
            if (x2 >= 0 && y1-1 >= 0) change[x2][y1-1] += degree;
            if (x1-1>=0 && y1-1>=0) change[x1-1][y1-1] -= degree;
        } else {
            change[x2][y2] += degree;
            if (y2 >= 0 && x1-1 >= 0) change[x1-1][y2] -= degree;
            if (x2 >= 0 && y1-1 >= 0) change[x2][y1-1] -= degree;
            if (x1-1>=0 && y1-1>=0) change[x1-1][y1-1] += degree;
        }
    }
    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }
    int garosum[n]; int serosum[m];
    int presum = 0;
    for (int i = 0; i < n; i++) {
        garosum[i] = 0;
        for (int j = 0; j < m; j++) {
            garosum[i] += change[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        serosum[i] = 0;
        for (int j = 0; j < n; j++) {
            serosum[i] += change[j][i];
        }
    }
    for (int i = 1; i < n; i++) {
        garosum[i] += garosum[i-1];
    }
    for (int i = 1; i < m; i++) {
        serosum[i] += serosum[i-1];
    }
    int whole = garosum[n-1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = whole;
            if (i > 0) dp[i][j] -= garosum[i-1];
            if (j > 0) dp[i][j] -= serosum[j-1];
        }
    }
    int dp2[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp2[i][j] = 0;
            dp2[i][j] += change[i][j];
            if (i>0) dp2[i][j] += dp2[i-1][j];
            if (j>0) dp2[i][j] += dp2[i][j-1];
            if (i>0 && j>0) dp2[i][j] -= dp2[i-1][j-1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int part = 0;
            if (i>0 && j>0) part = dp2[i-1][j-1];
            dp[i][j] += part;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j]+board[i][j] > 0) answer++;
        }
    }
    return answer;
}
