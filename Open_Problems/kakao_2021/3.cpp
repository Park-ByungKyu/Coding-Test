#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> string_parser(string str, int mode) {
    string a,b,c,d; int p,q,r,s; int score = 0;
    
    if (mode == 1) {
        int j = 0;
        while (true) {
            if (str[j] != ' ') {a.push_back(str[j]);j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') {b.push_back(str[j]);j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') {c.push_back(str[j]);j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') {d.push_back(str[j]);j++;}
            else {j++; break;}
        }
        while (j < str.size()) {
            if (str[j] != ' ') {score = score*10 + (str[j]-'0'); j++;}
            else {j++; break;}
        }
    }
    
    if (mode == 2) {
        int j = 0;
        while (true) {
            if (str[j] != ' ') { a.push_back(str[j]);j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') {j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') { b.push_back(str[j]);j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') {j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') { c.push_back(str[j]);j++;}
            else {j++; break;}
        }
            while (true) {
            if (str[j] != ' ') {j++;}
            else {j++; break;}
        }
        while (true) {
            if (str[j] != ' ') { d.push_back(str[j]);j++;}
            else {j++; break;}
        }
        while (j < str.size()) {
            if (str[j] != ' ') {score = score*10 + (str[j]-'0'); j++;}
            else {j++; break;}
        }
    }
    
    
    if (a == "java") p = 0;
    else if (a == "python") p = 1;
    else if (a == "cpp") p = 2;
    else p = 3;
    if (b == "backend") q = 0;
    else if (b == "frontend") q = 1;
    else q = 2;
    if (c == "junior") r = 0;
    else if (c == "senior") r = 1;
    else r = 2;
    if (d == "chicken") s = 0;
    else if (d == "pizza") s = 1;
    else s = 2;
    return {p,q,r,s, score};
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> ans[4][3][3][3];
    for (int i = 0; i < info.size(); i++) {
        vector<int> v1 = string_parser(info[i],1);
        ans[v1[0]][v1[1]][v1[2]][v1[3]].push_back(v1[4]);
        ans[v1[0]][v1[1]][v1[2]][2].push_back(v1[4]);
        ans[v1[0]][v1[1]][2][v1[3]].push_back(v1[4]);
        ans[v1[0]][2][v1[2]][v1[3]].push_back(v1[4]);
        ans[3][v1[1]][v1[2]][v1[3]].push_back(v1[4]);
        ans[3][2][v1[2]][v1[3]].push_back(v1[4]);
        ans[3][v1[1]][2][v1[3]].push_back(v1[4]);
        ans[3][v1[1]][v1[2]][2].push_back(v1[4]);
        ans[v1[0]][2][2][v1[3]].push_back(v1[4]);
        ans[v1[0]][2][v1[2]][2].push_back(v1[4]);
        ans[v1[0]][v1[1]][2][2].push_back(v1[4]);
        ans[3][2][2][v1[3]].push_back(v1[4]);
        ans[3][2][v1[2]][2].push_back(v1[4]);
        ans[3][v1[1]][2][2].push_back(v1[4]);
        ans[v1[0]][2][2][2].push_back(v1[4]);
        ans[3][2][2][2].push_back(v1[4]);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int r = 0; r < 3; r++) {
                    sort(ans[i][j][k][r].begin(), ans[i][j][k][r].end());
                }
            }
        }
    }
    for (int i = 0; i < query.size(); i++) {
        vector<int> v1 = string_parser(query[i],2);
        int r = ans[v1[0]][v1[1]][v1[2]][v1[3]].end() -lower_bound(ans[v1[0]][v1[1]][v1[2]][v1[3]].begin(), ans[v1[0]][v1[1]][v1[2]][v1[3]].end(), v1[4]) ;
        answer.push_back(r);
    }
    return answer;
}
