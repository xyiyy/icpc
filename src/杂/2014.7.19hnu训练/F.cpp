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
const int maxn = 2000010;
char a[maxn];
char b[maxn];
stack<char> s1;
stack<ll> s2;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll temp;
    ll temp2;
    while (cin.getline(a, maxn)) {
        if (a[0] == '#')break;
        while (!s1.empty())s1.pop();
        while (!s2.empty())s2.pop();
        int i = 0, j = 0;
        while (1) {
            if (a[i] == '\0')break;
            while (a[i] == ' ')i++;
            b[j++] = a[i++];
        }
        b[j] = '\0';
        i = 0;
        //	cout<<b<<endl;
        while (1) {
            if (b[i] == '\0')break;
            while (b[i] == ' ')i++;
            if (b[i] == 'S') {
                s1.push('S');
                i++;
                continue;
            }
            if (b[i] == '<') {
                i++;
                continue;
            }
            if (b[i] >= '0' && b[i] <= '9') {
                temp = 0;
                while (b[i] >= '0' && b[i] <= '9') {
                    temp = temp * 10 + b[i] - '0';
                    i++;
                }
                while (!s1.empty() && s1.top() == '^') {
                    s1.pop();
                    temp2 = s2.top();
                    s2.pop();
                    if (temp > 60) {
                        temp = 0;
                        temp2 = 0;
                    }
                    temp = (temp2 >> temp);
                }
                //	cout<<temp<<endl;
                s2.push(temp);
                continue;

            }
            if (b[i] == '>') {
                if (b[i + 1] == '>' && (b[i + 2] == 'S' || (b[i + 2] >= '0' && b[i + 2] <= '9'))) {
                    s1.push('^');
                    i++;
                }
                else if (s1.top() == 'S') {
                    s1.pop();
                    temp = s2.top();
                    s2.pop();
                    temp = (temp * temp) % MOD;
                    while (!s1.empty() && s1.top() == '^') {
                        s1.pop();
                        temp2 = s2.top();
                        s2.pop();
                        if (temp > 60) {
                            temp = 0;
                            temp2 = 0;
                        }
                        temp = (temp2 >> temp);
                    }
                    s2.push(temp);
                }
                i++;
                continue;
            }
        }
        cout << s2.top() << endl;
    }
    return 0;
}


