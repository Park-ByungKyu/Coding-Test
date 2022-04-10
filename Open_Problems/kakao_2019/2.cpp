#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(pair<double,int> p1, pair<double,int> p2) {
    if (p1.first > p2.first) {
        return true;
    }
    if (p1.first == p2.first) {
        if (p1.second < p2.second) return true;
    }
    return false;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int stagecnt[N+1]; int sum[N+1];
    for (int i = 0; i < N+1; i++) {stagecnt[i]=0; sum[i]=0;}
    for (int i = 0; i < stages.size(); i++) {
        stagecnt[stages[i]-1]++; 
    }
    sum[N] = stagecnt[N];
    for (int i = N; i >= 1; i--) {
        sum[i-1] = sum[i]+stagecnt[i-1];
    }
    vector<pair<double,int>> a;
    for (int i = 0; i < N; i++) {
        for (int j = 2; j <= N; j++) {
            while (stagecnt[i]!=0 && sum[i]!=0&&stagecnt[i]%j==0 && sum[i]%j==0) {
                stagecnt[i]/=j; sum[i]/=j;
            }
        }
        if (sum[i] == 0) a.push_back({0,i+1});
        else {
        double db = double(stagecnt[i])/double(sum[i]);
        a.push_back({db, i+1});
        }
    }
    sort(a.begin(), a.end(), compare);
    for (int i = 0; i < a.size(); i++) {
        answer.push_back(a[i].second);
    }
    return answer;
}
