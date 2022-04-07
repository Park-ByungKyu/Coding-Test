#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int k) {
    int answer = 0;
    vector<int> v;
    while (n != 0) {
        v.push_back(n%k);
        n = n/k;
    }
    
    long long tmp = 0;
    for (int i = v.size()-1; i >= 0; i--) {
        if (v[i] == 0) {
            int tag = 1;
            if (tmp == 1 || tmp == 0) tag = 0;
            for (long long j = 2; j*j <= tmp; j++) {
                if (tmp%j == 0) {tag = 0; break;}
            }
            if (tag == 1) answer++;
            
            tmp = 0;
        } else {
            tmp *= 10;
            tmp += v[i];
        }
    }
    int tag = 1;
            if (tmp == 1 || tmp == 0) tag = 0;
            for (long long j = 2; j*j <= tmp; j++) {
                if (tmp%j == 0) {tag = 0; break;}
            }
            if (tag == 1) answer++;
    return answer;
}
