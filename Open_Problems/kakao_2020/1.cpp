#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 2147483647;
    int n = s.size();
    for (int unit = 1; unit <= n; unit++) {
        vector<string> str;
        int p = 0;
        while (p < n) {
            string tmp;
            for (int i = 0; i < unit&&p<n; i++) {
                tmp.push_back(s[p]); p++;
            }
            str.push_back(tmp);
            tmp = "";
        }
        int ans = str[0].size(); int cnt = 1;
        for (int i = 1; i < str.size(); i++) {
            if (str[i-1] == str[i]) {
                cnt++;
            } else {
                if (cnt != 1) {
                    while (cnt != 0) {
                        ans++; cnt/=10;
                    }
                }
                ans += str[i].size();
                cnt = 1;
            }
        }
        if (cnt != 1) {
            while (cnt != 0) {ans++; cnt/=10;}
        }
        if (answer > ans) answer = ans;
    }
    return answer;
}
