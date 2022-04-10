#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int n = record.size();
    map<string,string> mp;
    vector<pair<string,string>> ans;
    
    for (int i = 0; i < n; i++) {
        string a; string b; string c;
        int m = record[i].size();
        int j = 0;
        while (record[i][j] != ' ') {
            a.push_back(record[i][j]); j++;
        }
        j++;
        while (j!=m && record[i][j] != ' ') {
            b.push_back(record[i][j]); j++;
        }
        j++;
        while (j < m) {
            c.push_back(record[i][j]); j++;
        }
        if (a == "Enter") {
            mp[b] = c;
            ans.push_back({"E",b});
        }
        else if (a == "Leave") {
            //mp.erase(b);
            ans.push_back({"L",b});
        }
        else if (a == "Change") {
            mp[b] = c;
        }
    }
    vector<pair<string,string>> hash;
    for (auto iter:mp) {
        hash.push_back({iter.first,iter.second}); 
    }
    sort(hash.begin(), hash.end());
    
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].first == "E") {
            string p;
            string key = ans[i].second;
            int s = 0; int e = hash.size()-1;
            while (s<=e) {
                int m = (s+e)/2;
                if (hash[m].first == key) {
                    p = hash[m].second; break;
                }
                else if (hash[m].first < key) {
                    s = m+1;
                } else {
                    e = m-1;
                }
            }
            
            p = p + "님이 들어왔습니다.";
            answer.push_back(p);
        }
        else {
            string p;
            string key = ans[i].second;
            int s = 0; int e = hash.size()-1;
            while (s<=e) {
                int m = (s+e)/2;
                if (hash[m].first == key) {
                    p = hash[m].second; break;
                }
                else if (hash[m].first < key) {
                    s = m+1;
                } else {
                    e = m-1;
                }
            }
            
            
            p = p + "님이 나갔습니다.";
            answer.push_back(p);
        }
    }
    return answer;
}
