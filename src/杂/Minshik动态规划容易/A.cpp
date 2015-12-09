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

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
int dp[2][25010];
//vector<pair<int,int> >a[110];
int B[110][110], P[110][110];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        //int b,p;
        memset(dp, 0, sizeof(dp));
        memset(P, 0, sizeof(P));
        memset(B, 0, sizeof(B));
        cin >> n;
        int cur = 1;
        int m1;
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                //cin>>b>>p;
                //a[i].PB(MP(b,p));
                cin >> B[i][j] >> P[i][j];
            }
            //if(i==0)
            //	for(int j=0;j<m;j++)
            //	{
            //		dp[i][P[0][j]]=B[0][j];
            //
            //	}
            //	else
            //	{
            //	for(int k=0;k<100010;k++)

            //	}
            //	cur=1-cur;m1=m;
        }
        for (int j = 0; P[0][j]; j++) {
            if (dp[0][P[0][j]])
                dp[0][P[0][j]] = max(B[0][j], dp[0][P[0][j]]);
            else
                dp[0][P[0][j]] = B[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 25010; j++) {
                dp[cur][j] = 0;
            }
            for (int j = 0; j < 25010; j++) {
                if (dp[1 - cur][j]) {
                    for (int k = 0; P[i][k]; k++) {
                        if (dp[cur][j + P[i][k]])
                            dp[cur][j + P[i][k]] = max(min(dp[1 - cur][j], B[i][k]), dp[cur][j + P[i][k]]);
                        else
                            dp[cur][j + P[i][k]] = min(dp[1 - cur][j], B[i][k]);
                    }

                }
            }
            cur = 1 - cur;
        }
        double maxn = 0;
        for (int i = 0; i < 25010; i++) {
            if (dp[1 - cur][i]) {
                if (dp[1 - cur][i] > maxn * i) {
                    maxn = (double) (dp[1 - cur][i] * 1.0) / (double) (i * 1.0);
                }
            }
        }
        cout << fixed << setprecision(3) << maxn << endl;
    }


    return 0;
}

