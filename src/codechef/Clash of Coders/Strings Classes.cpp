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
string str;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> str) {
        if (str == "*END*")break;
        cout << str << " ";
        int len = str.length();
        if (len < 2) {
            cout << "NO" << endl;
            continue;
        }
        bool flag = 0;
        int a = 0;
        int b = 0;
        for (int i = 1; i < len; i++) {
            a = b = 0;
            for (int j = 0; j < i; j++) {
                if (str[j] != str[i - j - 1])a++;
            }
            for (int j = i; j < len; j++) {
                if (str[j] != str[len - 1 - (j - i)])b++;
            }
            // cout<<a<<" "<<b<<" "<<i<<" "<<(len-i)<<endl;
            if ((a == 2 || (i % 2 == 1 && a == 0)) && (b == 2 || (b == 0 && (len - i) % 2 == 1)))flag = 1;
        }
        if (flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}


