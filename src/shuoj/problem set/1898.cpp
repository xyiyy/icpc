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
char a[110] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int temp[100010];
map<char, int> ms;

int main() {
    ios::sync_with_stdio(false);
    int t;
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        ms[a[i]] = i;
    }
    cin >> t;
    //getchar();
    while (t--) {
        CLR(str, 0);
        CLR(temp, 0);
        while (cin.getline(str, 10010, '\n')) {
            len = strlen(str);
            if (len)break;
        }
        while (len && str[len - 1] == '=') {
            len--;
        }
        int tot = 0;
        for (int i = 0; i < len; i++) {
            int tmp = ms[str[i]];
            for (int j = 0; j < 6; j++) {
                temp[tot++] = (tmp & (1 << (5 - j))) > 0;
            }
        }
        tot -= tot % 8;
        for (int i = 0; i < tot;) {
            int tmp = 0;
            for (int j = 0; j < 8; j++, i++) {
                tmp <<= 1;
                tmp = tmp | temp[i];
                //cout<<temp[i]<<" ";
            }
            //cout<<endl;
            //cout<<tmp<<endl;
            cout << (char) tmp;
        }
        cout << endl;
    }
    return 0;
}



