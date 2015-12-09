//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
char str[100010];
const int SZ = 333;
int A[SZ][30];
int minn[SZ];
int maxx[SZ];
int gao[30];
int f[SZ];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < SZ; i++) {
        minn[i] = INF;
        maxx[i] = -INF;
    }
    for (int i = 0; i < SZ; i++)f[i] = 2;
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", str);
    int tot = (n - 1) / SZ + 1;
    for (int i = 0; i < n; i++) {
        int j = i / SZ;
        str[i] -= 'a';
        A[j][str[i]]++;
        minn[j] = min(minn[j], i);
        maxx[j] = max(maxx[j], i);
    }
    for (int i = 0; i < q; i++) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        l--;
        r--;
        int tl = l;
        int tr = r;
        CLR(gao, 0);
        for (int j = 0; j < tot; j++) {
            l = max(minn[j], tl);
            r = min(maxx[j], tr);
            if (l == minn[j] && r == maxx[j]) {
                for (int k = 0; k < 26; k++) {
                    gao[k] += A[j][k];
                    A[j][k] = 0;
                }
            } else if (r >= l) {
                if (f[j] == 1) {
                    int x = minn[j];
                    for (int k = 0; k < 26; k++) {
                        int num = A[j][k];
                        while (num--) {
                            str[x] = k;
                            x++;
                        }
                    }
                } else if (f[j] == 0) {
                    int x = maxx[j];
                    for (int k = 0; k < 26; k++) {
                        int num = A[j][k];
                        while (num--) {
                            str[x] = k;
                            x--;
                        }
                    }
                }
                f[j] = 2;
                for (int k = l; k <= r; k++) {
                    gao[str[k]]++;
                    A[j][str[k]]--;
                }
            }
        }
        for (int j = 0; j < tot; j++) {
            l = max(minn[j], tl);
            r = min(maxx[j], tr);
            if (l == minn[j] && r == maxx[j]) {
                if (c) {
                    int len = r - l + 1;
                    for (int k = 0; k < 26; k++) {
                        int tmp = min(len, gao[k]);
                        len -= tmp;
                        A[j][k] += tmp;
                        gao[k] -= tmp;
                    }
                } else {
                    int len = r - l + 1;
                    for (int k = 25; k >= 0; k--) {
                        int tmp = min(len, gao[k]);
                        len -= tmp;
                        A[j][k] += tmp;
                        gao[k] -= tmp;
                    }
                }
                f[j] = c;
            } else if (r >= l) {
                if (c) {
                    int x = l;
                    for (int k = 0; k < 26; k++) {
                        while (x <= r && gao[k]) {
                            gao[k]--;
                            str[x] = k;
                            x++;
                            A[j][k]++;
                        }
                    }
                } else {
                    int x = l;
                    for (int k = 25; k >= 0; k--) {
                        while (x <= r && gao[k]) {
                            gao[k]--;
                            str[x] = k;
                            x++;
                            A[j][k]++;
                        }
                    }
                }
            }
        }
    }
    //cout<<"ok"<<endl;
    for (int i = 0; i < tot; i++) {
        if (f[i] == 2)continue;
        if (f[i] == 1) {
            int x = minn[i];
            for (int k = 0; k < 26; k++) {
                int num = A[i][k];
                while (num--) {
                    str[x] = k;
                    x++;
                }
            }
        } else if (f[i] == 0) {
            int x = maxx[i];
            for (int k = 0; k < 26; k++) {
                int num = A[i][k];
                while (num--) {
                    str[x] = k;
                    x--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)printf("%c", str[i] + 'a');
    printf("\n");
    return 0;
}

