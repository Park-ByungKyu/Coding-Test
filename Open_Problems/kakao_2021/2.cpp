#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<string> ans[11];
    for (int i = 0; i < orders.size(); i++) {
            string s = orders[i];
            int n = s.size();
            
            int comb = 1<<n;
            for (int k = 0; k < comb; k++) {
                string tmp = ""; int cmb = k;
                for (int a = 0; a < n; a++) {
                    if (cmb%2 == 1) {
                        tmp.push_back(s[a]);
                    } cmb/=2;
                }
                ans[tmp.size()].push_back(tmp);
            }
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            string a = ans[i][j];
            char arr[a.size()];
            for (int k = 0; k < a.size(); k++) {
                arr[k] = ans[i][j][k]; 
            }
            sort(arr, arr+a.size());
            string b;
            for (int i = 0; i < a.size(); i++) {
                b.push_back(arr[i]);
            }
            ans[i][j] = b;
        }
        sort(ans[i].begin(), ans[i].end());
    }
    
    for (int i = 0; i < course.size(); i++) {
        int len = course[i];
        vector<string> v1 = ans[len];
        vector<string> l[21];
        int cnt = 0;
        for (int i = 1; i < v1.size(); i++) {
            if (v1[i] == v1[i-1]) {
                cnt++;
            } else {
                l[cnt].push_back(v1[i-1]);
                cnt = 0;
            }
        }
        //cout << cnt << '\n';
        if (v1.size()>=1) l[cnt].push_back(v1[v1.size()-1]);
        
        for (int j = 20; j >= 1; j--) {
            if (l[j].size() != 0) {
                for (int k = 0; k < l[j].size(); k++) {
                    answer.push_back(l[j][k]);
                }
                break;
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
