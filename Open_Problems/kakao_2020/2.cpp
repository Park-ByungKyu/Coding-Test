#include <string>
#include <vector>

using namespace std;

bool judge_balance(string p) {
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;
    }
    if (cnt == 0) return true;
    else return false;
}
bool judge_correct(string p) {
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    } return true;
}
string resursion(string w) {
    string empty = "";
    if (w.size() == 0) return empty;
    else {
        string u = ""; string v = "";
        int cnt = 0;
        for (int i = 0; i < w.size(); i++) {
            if (w[i] == '(') cnt++;
            else cnt--;
            if (cnt == 0) {
                for (int j = 0; j <= i; j++) {
                    u.push_back(w[j]);
                }
                for (int j = i+1; j < w.size(); j++) {
                    v.push_back(w[j]);
                }
                break;
            }
        }
        if (judge_correct(u) == true) {
            return u+resursion(v);
        } else {
            string ret = "("+resursion(v)+")";
            string newu;
            for (int i = 1; i < u.size()-1; i++) {
                if (u[i] == '(') newu.push_back(')');
                else newu.push_back('(');
            }
            return ret+newu;
        }
    }
}
string solution(string p) {
    string answer = "";
    if (judge_correct(p) == true) return p;
    else answer = resursion(p);
    return answer;
}
