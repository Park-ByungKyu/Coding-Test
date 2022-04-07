#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cal (string a, string b) {
    int h1 = 0; int h2 = 0;
    int m1 = 0; int m2 = 0;
    h1 = h1 + (a[0]-'0') * 10;
    h1 = h1 + (a[1]-'0');
    m1 = m1 + (a[3]-'0') * 10;
    m1 = m1 + (a[4]-'0');
    h2 = h2 + (b[0]-'0') * 10;
    h2 = h2 + (b[1]-'0');
    m2 = m2 + (b[3]-'0') * 10;
    m2 = m2 + (b[4]-'0');
    int ret = 0;
    ret = (h2-h1)*60+(m2-m1);
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int n = records.size();
    vector<pair<pair<string,string>,int>> rec; // 차량번호, 입차시간, 누적시간
    
    for (int i = 0; i < n; i++) {
        string time; string num; bool isin;
        for (int j = 0; j < 5; j++) {
            time.push_back(records[i][j]);
        }
        for (int j = 6; j < 10; j++) {
            num.push_back(records[i][j]);
        }
        if (records[i][11] == 'I') isin = 1;
        else isin = 0;
        
        // 입차
        if (isin == 1) {
            int tag = 0;
            for (int i = 0; i < rec.size(); i++) {
                if (rec[i].first.first == num) {
                    rec[i].first.second = time; tag = 1; break;
                }
            }
            if (tag == 0) {
                rec.push_back({{num,time},0});
            }
        }
        // 출차
        else {
            for (int i = 0; i < rec.size(); i++) {
                if (rec[i].first.first == num) {
                    rec[i].second += cal(rec[i].first.second,time);
                    rec[i].first.second = "0";
                    break;
                }
            }
        }
    }
    
    sort(rec.begin(), rec.end());
    for (int i = 0; i < rec.size(); i++) {
        int tm = rec[i].second;
        if (rec[i].first.second != "0") {
            tm += cal(rec[i].first.second, "23:59");
        }
        int topush = 0;
        if (tm <= fees[0]) {
            topush = fees[1];
        } else {
            tm = tm - fees[0];
            topush = fees[1];
            topush += (tm/fees[2]) * fees[3];
            if (tm%fees[2] != 0) {
                topush += fees[3];
            }
        }
        answer.push_back(topush);
    }
    return answer;
}
