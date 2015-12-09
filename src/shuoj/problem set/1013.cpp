#include<stdio.h>
#include<iostream>

using namespace std;
long long ch[21][21] = {0};
int n, m, x, y;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void horse() {
    int i;
    ch[x][y] = -1;
    for (i = 0; i < 8; i++) {
        if ((x + dx[i] >= 0 && x + dx[i] <= n) && (y + dy[i] >= 0) && (y + dy[i]) <= m) {
            ch[x + dx[i]][y + dy[i]] = -1;
        }
    }
}

void search() {
    for (int i = 0; i <= n; i++) {
        if (ch[i][0] != -1)
            ch[i][0] = 1;
        else break;
    }
    for (int i = 0; i <= m; i++) {
        if (ch[0][i] != -1)
            ch[0][i] = 1;
        else break;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ch[i][j] != -1) {
                if ((ch[i - 1][j] != -1) && (ch[i][j - 1] != -1)) {
                    ch[i][j] = ch[i - 1][j] + ch[i][j - 1];
                }
                if ((ch[i - 1][j] == -1) && (ch[i][j - 1] != -1)) {
                    ch[i][j] = ch[i][j - 1];
                }
                if ((ch[i - 1][j] != -1) && (ch[i][j - 1] == -1)) {
                    ch[i][j] = ch[i - 1][j];
                }
                if ((ch[i - 1][j] == -1) && (ch[i][j - 1] == -1)) {
                    ch[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    while (cin >> n >> m >> x >> y && (x != 0 || y != 0 || n != 0 || m != 0)) {
        horse();
        search();
        printf("%lld\n", ch[n][m]);
        n = 0;
        m = 0;
        x = 0;
        y = 0;
    }
    return 0;
}
		
		
		
		
