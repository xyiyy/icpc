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
int a[110][110];

int main() {
    ios::sync_with_stdio(false);
    int n, tot, x, y;
    int cas = 1;
    while (cin >> n) {
        CLR(a, 0);
        tot = 1;
        x = 0;
        y = 0;
        a[0][0] = 1;
        while (tot < n * n) {
            while (x + 1 < n && !a[x + 1][y])a[++x][y] = ++tot;
            while (y + 1 < n && !a[x][y + 1])a[x][++y] = ++tot;
            while (x - 1 >= 0 && !a[x - 1][y])a[--x][y] = ++tot;
            while (y - 1 >= 0 && !a[x][y - 1])a[x][--y] = ++tot;
        }
        //  cout<<"Case "<<cas++<<":";

        if (cas != 1)cout << endl;
        cas++;
        // cout<<"n="<<n<<endl;
        for (int i = 0; i < n; i++) {
            cout << a[i][0];
            for (int j = 1; j < n; j++) {
                cout << " " << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}  
