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
unsigned long long dp[110][110];
char a[10];
unsigned long long num[110];
unsigned long long fac[110];
unsigned long long gao[110];

int main() {
    ios::sync_with_stdio(false);
    int t;
    fac[0] = 1;
    for (unsigned long long i = 1; i < 53; i++) {
        fac[i] = fac[i - 1] * i;
    }

    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        CLR(num, 0);
        for (int i = 0; i < n; i++) {
            scanf("%s", a);
            if (a[0] >= '2' && a[0] < +'9') {
                temp = a[0] - '0';
            }
            else if (a[0] == 'T')temp = 0;
            else if (a[0] == 'J')temp = 10;
            else if (a[0] == 'Q')temp = 11;
            else if (a[0] == 'K')temp = 12;
            else if (a[0] == 'A')temp = 1;
            /*if(a[1]=='S')temp= temp *4;
            else if(a[1]=='H')temp = temp *4+1;
            else if(a[1]=='D')temp = temp *4+2;
            else if(a[1]=='C')temp =temp *4+3;*/
            num[temp]++;
        }
        unsigned long long t22 = 2, t32 = 6, t42 = 12, t4 = 24;
        for (int i = 0; i < 13; i++) {
            if (num[i] == 2) {
                gao[i] = fac[n - 1];
            } else if (num[i] == 3) {
                gao[i] = t32 * fac[n - 1] - t32 * fac[n - 2];
            } else if (num[i] == 4) {
                gao[i] = t42 * fac[n - 1] - t4 * fac[n - 2] + t4 * fac[n - 3];
            }
        }
        for (int i = 0; i <)
            /*for(int i=0;i<52;i++){
                if(num[i])dp[0][i][1]=1;
            }
            for(int i=0;i<52;i++){
                for(int j=0;j<52;j++){
                    if(i/4)
                }
            }*/
            return 0;
    }


