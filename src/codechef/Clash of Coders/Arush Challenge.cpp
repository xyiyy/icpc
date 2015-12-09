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
int a, b, c, d;

void solve(int x) {
    if (x == 9) {
        d++;
        b += 2;
        a++;
    } else if (x == 8) {
        d++;
        a += 3;
    } else if (x == 7) {
        d++;
    } else if (x == 6) {
        c++;
        b++;
    } else if (x == 5) {
        c++;
    } else if (x == 4) {
        b++;
        a += 2;
    } else if (x == 3) { b++; }
    else if (x == 2) {
        a++;
    } else { ;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string str;
    while (t--) {
        int n;
        cin >> n;
        cin >> str;
        for (int i = 0; i < n; i++) {
            solve(str[i] - '0');
        }
        for (int i = 0; i < d; i++)cout << "7";
        for (int i = 0; i < c; i++)cout << "5";
        for (int i = 0; i < b; i++)cout << "3";
        for (int i = 0; i < a; i++)cout << "2";
        a = b = c = d = 0;
        cout << endl;
    }
    return 0;
}


