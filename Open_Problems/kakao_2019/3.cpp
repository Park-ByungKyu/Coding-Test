#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int n = relation.size();
    int m = relation[0].size();
    
    int comb = 1<<m;
    vector<int> ans;
    
        for (int i = 0; i < comb; i++) {
            vector<vector<string>> v;
            int tmp = i;
            for (int k = 0; k < n; k++) {
                vector<string> st;
                for (int j = 0; j < m; j++) {
                    if (tmp%2 == 1) {
                        st.push_back(relation[k][j]);
                    } tmp/=2;
                }
                v.push_back(st);
                tmp = i;
            }
            sort(v.begin(), v.end());
            int tag = 1;
            for (int p = 0; p < v.size()-1; p++) {
                if (v[p] == v[p+1]) {tag = 0; break;}
            }
            if (tag == 1) ans.push_back(i);
        }
    int q = ans.size();
    bool isans[q];
    for (int i = 0; i < q; i++) isans[i]=true;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < q; j++) {
            if (i!=j) {
                if ((ans[i]&ans[j])==ans[i]) {
                    isans[j]=false;
                }
                if ((ans[i]&ans[j])==ans[j]) {
                    isans[i]=false;
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if (isans[i]==true) answer++;
    }
    return answer;
}
