#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> rotate (vector<vector<int>>& key) {
    vector<vector<int>> ret;
    int m = key.size();
    ret.resize(m, vector<int>(m,0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ret[i][j] = key[j][m-1-i];
        }
    }
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(); int n = lock.size();
    for (int a = 0; a < 4; a++) {
        key = rotate(key);
        for (int i = -m+1; i < n; i++) {
            for (int j = -m+1; j < n; j++) {
                vector<vector<int>> tmp = lock;
                int tag = 1;
                for (int a = 0; a < m; a++) {
                    for (int b = 0; b < m; b++) {
                        if (i+a>=0&&i+a<n&&j+b>=0&&j+b<n) {
                            if (tmp[i+a][j+b] == 0 && key[a][b] == 1) {
                                tmp[i+a][j+b] = 1;
                            }
                            else if (tmp[i+a][j+b] == 1 && key[a][b] == 1) {
                                tag = 0;
                            }
                        }
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (tmp[i][j] == 0) tag = 0;
                    }
                }
                if (tag == 1) return true;
            }
        }
    }
    return false;
}
