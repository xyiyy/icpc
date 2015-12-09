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

char a[110];

int main() {
    ios::sync_with_stdio(false);
    stack<int> s;
    int len;
    int num;
    int cas = 1, flag = 1;
    while (s.size())s.pop();
    while (cin >> a) {
        if (flag == 1) {
            if (cas != 1)cout << endl;
            cout << "Case " << cas++ << ":" << endl;
            flag = 0;
        }
        if (a[0] == '#') {
            while (!s.empty())s.pop();
            //	cout<<endl;
            flag = 1;
        }
        else if (a[1] == 'U' && flag == 0) {
            cin >> num;
            s.push(num);
        }
        else if (a[1] == 'O' && flag == 0) {
            if (!s.empty()) {
                //if(s.top()==-15)cout<<2<<endl;

                cout << s.top() << endl;
                s.pop();
            }
            else {
                cout << "Error" << endl;
                flag = 2;
            }
        }
    }
    return 0;
}


