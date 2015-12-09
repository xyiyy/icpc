#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int h[101][101];
int dis_sk[101][101];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
int r, c;

int dis(int i, int j) {
    int temp;
    if (dis_sk[i][j])return dis_sk[i][j];
    for (int k = 0; k < 4; k++) {
        if ((i + dx[k]) >= 0 && (i + dx[k]) < r && (j + dy[k]) >= 0 && (j + dy[k]) < c &&
            h[i][j] > h[i + dx[k]][j + dy[k]]) {
            temp = dis(i + dx[k], j + dy[k]);
            dis_sk[i][j] = dis_sk[i][j] > temp ? dis_sk[i][j] : temp + 1;
        }
    }
    return dis_sk[i][j];
}

int main() {
    int max_dis = 0;
    int temp;
    while (cin >> r >> c) {
        max_dis = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> h[i][j];
                dis_sk[i][j] = 0;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                temp = dis(i, j);
                max_dis = max_dis > temp ? max_dis : temp;
            }
        }
        cout << max_dis + 1 << endl;
    }
    return 0;
}
	





