#include <bits/stdc++.h>
using namespace std;

bool isPrimeNumber(int N) {
    if (N==1) return false;
    for (int i = 2; i <= N/2; i++) {
        if (N%i == 0) return false;
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc, n; cin >> tc; 
    int cnt = 0;
    for (int i = 0; i < tc; i++) {
        int n; cin >> n;
        if (isPrimeNumber(n)) cnt++;
    }
    cout << cnt;
}
