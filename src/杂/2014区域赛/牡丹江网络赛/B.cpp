//gaoshenbaoyou  ------ pass system test
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
char a[110][110];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        CLR(a, 0);
        cin >> n;
        if (n == 1) {
            cout << "B" << endl;
            continue;
        }
        if (n == 2 || n == 3 || n == 4) {
            cout << "No solution!" << endl;
            continue;
        }
        if (n == 5) {
            cout << "YYYGR" << endl;
            cout << "YGGGR" << endl;
            cout << "YGYYR" << endl;
            cout << "BYYYR" << endl;
            cout << "BBBBR" << endl;
            continue;
        }
        if (n == 6) {
            cout << "RYYYRG" << endl;
            cout << "RYGYRG" << endl;
            cout << "RYGRRG" << endl;
            cout << "RGGRGG" << endl;
            cout << "RGGRGB" << endl;
            cout << "RBBBBB" << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            a[i][0] = 1;
        }
        for (int i = 1; i < n; i++)a[n - 1][i] = 4;
        a[n - 2][n - 1] = 4;
        //	cout<<n-2<<"  "<<n-1<<endl;
        for (int j = (n + 1) / 2 + 1; j < n; j++) {
            int k = j % 2 + 1;
            a[j - 2][j] = k;
            a[j - 2][j - 1] = k;
            for (int i = 0; i < j - 2; i++) {
                a[i][j] = k;
            }
            for (int i = j - 1; i < n - 1; i++) {
                a[i][j - 1] = k;
            }
        }
        for (int j = (n + 1) / 2; j > 3; j--) {
            int k = j % 2 + 1;
            a[j - 2][j] = k;
            a[j - 2][j - 1] = k;
            a[j - 2][j - 2] = k;
            for (int i = 0; i < j - 2; i++) {
                a[i][j] = k;
            }
            //	cout<<j<<"ok"<<endl;
            for (int i = j - 1; i < n - 2; i++) {
                a[i][j - 2] = k;
            }
            //cout<<j<<"ok"<<endl;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < 4; j++) {
                a[i][j] = 4;
            }
        }
        for (int i = 0; i < n - 6; i++) {
            a[i + 2][1] = 4;
        }
        //cout<<"ok"<<endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1)cout << "R";
                else if (a[i][j] == 2)cout << "G";
                else if (a[i][j] == 0)cout << "Y";
                else if (a[i][j] == 4)cout << "B";
            }
            cout << endl;
        }
    }

    return 0;
}



