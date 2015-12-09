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
char a[30][100];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j <= i) {
                a[i][j] = 'A' + j;
            }
            else a[i][j] = a[i][i] - (j - i);
        }
    }
//	for(int i=0;i<26;i++)
//	{
//		cout<<a[i]<<endl;
//	}
    int n;
    int cas = 1;
    int i;
    while (cin >> n) {
        cout << "Case " << cas++ << ": n=" << n << endl;
        if (n <= 26 && n > 0) {
            for (i = 0; i < n; i++) {
                for (int j = i; j < n - 1; j++)cout << " ";
                cout << a[i] << endl;
            }
            for (; i < 2 * n - 1; i++) {
                for (int j = i - n; j >= 0; j--)cout << " ";
                cout << a[2 * n - 2 - i] << endl;
            }
        }
        else cout << "No image!" << endl;
        cout << endl;
    }

    return 0;
}


