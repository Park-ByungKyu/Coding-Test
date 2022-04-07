#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<vector<int>> ans[100];
    for (int comb = 0; comb < 2048; comb++) {
        int r = comb;
        int lion = 0; int apeach = 0; int correct = 0;
        vector<int> arrow;
        for (int i = 10; i >= 0; i--) {
            int a = r % 2; r /= 2;
            if (a == 1) {
                lion += (10-i);
                correct += (info[i]+1);
                arrow.push_back(info[i]+1);
            }
            else {
                if (info[i] != 0) apeach += (10-i);
                arrow.push_back(0);
            }
        }
        if (lion > apeach && correct <= n) {
            arrow[0] += (n-correct);
            ans[lion-apeach].push_back(arrow);
        }
    }
    
    for (int i = 0; i < 100; i++) {
        sort(ans[i].begin(), ans[i].end());
    }
    for (int i = 99; i >= 0; i--) {
        if (ans[i].size() != 0) {
            for (int j = 10; j >= 0; j--) {
                answer.push_back(ans[i][ans[i].size()-1][j]);
            }
            return answer;
        }
    }
    return {-1};
}
