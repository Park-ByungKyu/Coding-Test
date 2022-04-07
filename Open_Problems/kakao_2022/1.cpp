#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int n = id_list.size();
    for (int i = 0; i < n; i++) answer.push_back(0);
    int reported[n][n];
    for (int i= 0; i < n; i++) {
        for (int j = 0; j < n; j++) reported[i][j] = 0;
    }
    
    int m = report.size();
    for (int i = 0; i < m; i++) {
        string a; string b;
        int j = 0;
        for (j = 0; j < report[i].size() && report[i][j] != ' '; j++) {
            a.push_back(report[i][j]);
        } j++;
        while (j < report[i].size()) {
            b.push_back(report[i][j]); j++;
        }
        int v1, v2;
        for (int i = 0; i < n; i++) {
            if (id_list[i] == a) {
                v1 = i;
            }
            if (id_list[i] == b) {
                v2 = i;
            }
        }
        reported[v1][v2] = 1;
    }
    int poor[n];
    for (int i = 0; i < n; i++) poor[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (reported[i][j] == 1) {
                poor[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (poor[i] >= k) {
            for (int j = 0; j < n; j++) {
                if (reported[j][i] == 1) {
                    answer[j]++;
                }
            }
        }
    }
    return answer;
}
