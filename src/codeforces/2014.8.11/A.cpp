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
int a[100010];
int b[100010];

int main() {
    ios::sync_with_stdio(false);
    string s1, s2;
    freopen("a.in", "r", stdin);
    while (cin >> s1 >> s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        CLR(a, 0);
        CLR(b, 0);
        int max1 = 0, max2 = 0;
        for (int i = 0; i < len1; i++) {
            if (s1[len1 - 1 - i] == '1') {
                a[i] = 1;
                max1 = max(i, max1);
            }
            else a[i] = 0;
        }
        for (int i = 0; i < len2; i++) {
            if (s2[len2 - 1 - i] == '1') {
                b[i] = 1;
                max2 = max(i, max2);
            }
            else b[i] = 0;
        }
        for (int i = max1; i >= 0; i--) {
            max1 = max(i, max1);
            while (a[i] && a[i + 1]) {
                a[i]--;
                a[i + 1]--;
                a[i + 2]++;

                i = i + 3;
                break;
            }
        }
        //	cout<<max1<<endl;
        for (int i = max2; i >= 0; i--) {
            max2 = max(i, max2);
            while (b[i] && b[i + 1]) {
                b[i]--;
                b[i + 1]--;
                b[i + 2]++;

                i = i + 3;
                break;
            }
            //cout<<i<<endl;
        }
        //	for(int i=0;i<=max1;i++)
        //	{
        ///		cout<<a[i];
        //	}cout<<endl;
        //	cout<<max2<<endl;
        //	for(int i=0;i<=max2;i++)
        //	{
        ///		cout<<b[i];
        //	}
        //	cout<<endl;
        if (max1 > max2) {
            cout << ">" << endl;
        }
        else if (max2 > max1) {
            cout << "<" << endl;
        }
        else if (max1 == max2) {
            int id = max1;
            while (id >= 0) {
                if (a[id] == 1 && b[id] == 0) {
                    cout << ">" << endl;
                    break;
                }
                else if (b[id] == 1 && a[id] == 0) {
                    cout << "<" << endl;
                    break;
                }
                id--;
            }
            if (id < 0)cout << "=" << endl;
        }
    }

    return 0;
}


