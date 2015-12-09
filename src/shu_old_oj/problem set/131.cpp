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
const int N = 100010;
char a[N];
bool mark[N];
char b;

int main() {
    ios::sync_with_stdio(false);
    int k = 1;
    int l, r;
    while (cin.getline(a, N, '\n')) {
        l = r = 0;
        a[strlen(a)] = ' ';
        cout << "Case " << k++ << ": ";
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] >= 'A' && a[i] <= 'Z') {
                mark[i] = 1;
                a[i] = a[i] + 'a' - 'A';
            }
        }
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] == 't' && a[i + 1] == 'h' && a[i + 2] == 'e' && (a[i + 3] == ' ' || a[i + 3] == '-')) {
                i += 3;
            }
            else if (a[i] == 'a' && (a[i + 1] == ' ' || a[i + 1] == '-')) {
                i++;
            }
            else if (a[i] == 'a' && a[i + 1] == 'n' && (a[i + 2] == ' ' || a[i + 2] == '-')) {
                i += 2;
            }
            else if (a[i] == 'o' && a[i + 1] == 'f' && (a[i + 2] == ' ' || a[i + 2] == '-')) {
                i += 2;
            }
            else if (a[i] == 'f' && a[i + 1] == 'o' && a[i + 2] == 'r' && (a[i + 3] == ' ' || a[i + 3] == '-')) {
                i += 3;
            }
            else if (a[i] == 'a' && a[i + 1] == 'n' && a[i + 2] == 'd' && (a[i + 3] == ' ' || a[i + 3] == '-')) {
                i += 3;
            }
            else if (a[i] >= 'a' && a[i] <= 'z') {
                if (mark[i])cout << (char) (a[i] + 'A' - 'a');
                else cout << a[i];
                while (a[i] != ' ' && a[i] != '-')i++;
            }
        }
        cout << endl;
        CLR(a, '\0');
    }
    return 0;
}

